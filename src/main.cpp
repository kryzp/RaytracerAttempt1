#include <iostream>

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL.h>
#include <glad/glad.h>

#include "app.h"
#include "renderer_2d.h"
#include "camera.h"
#include "input.h"

#include "wrapper/shader.h"
#include "wrapper/shader_mgr.h"

#include "wrapper/texture.h"
#include "wrapper/texture_mgr.h"

static const inline glm::mat4 SCREEN_ORTHO_MAT4      = glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f, 0.0f, 1000.0f);
static const inline glm::mat4 WORLD_PROJECTION_MAT4  = glm::perspective(30.0f, 1280.0f / 720.0f, 0.1f, 10000.0f);

static float g_time = 0.0f;
static float g_sample = 0.0f;

int main(int argc, char** argv)
{
    if (!App::inst()->init())
    {
        std::cout << "Failed to initialize App::" << std::endl;
        return -1;
    }

    ShaderMgr::inst()->load_shaders();
    TextureMgr::inst()->load_textures();

    Renderer2D::inst()->init();

    Shader& RAYTRACE_COMPUTE_SHADER = ShaderMgr::inst()->get_shader("C_RAYTRACE");

    Texture& skybox_texture = TextureMgr::inst()->get_texture("SKYBOX");

    Texture target;
    target.create(1280, 720, GL_RGBA, GL_RGBA32F, GL_UNSIGNED_BYTE, nullptr);

    Camera camera;

    GLuint n_groups_x = glm::ceil(1280.0f / 16.0f);
    GLuint n_groups_y = glm::ceil(720.0f / 16.0f);

    Uint64 t_now = SDL_GetPerformanceCounter();
    Uint64 t_last = 0;
    float t_delta = 0.0f;

    while (App::inst()->running())
    {
        App::inst()->poll_events();

        t_last = t_now;
        t_now = SDL_GetPerformanceCounter();
        t_delta = (float)((float)(t_now - t_last) / (float)SDL_GetPerformanceFrequency());

        // main
        {
            auto mouse_position = Input::inst()->mouse_position() - glm::vec2(1280 / 2, 720 / 2);

            if (Input::inst()->pressed_key(INP_KEY_ESCAPE))
                App::inst()->exit();

            auto pos0 = camera.position();
            camera.move(mouse_position);
            auto pos1 = camera.position();

            if (pos0 != pos1)
            {
                g_time = 0.0f;
                g_sample = 0.0f;
            }

            target.bind_image(0);
            skybox_texture.bind_image(1);

            RAYTRACE_COMPUTE_SHADER.use()
                .set_float("u_time", g_time)
                .set_mat4("u_view_matrix", camera.view_matrix())
                .set_mat4("u_inverse_projection", glm::inverse(WORLD_PROJECTION_MAT4))
                .dispatch_compute(n_groups_x, n_groups_y,1)
                .wait_compute();

            Renderer2D::inst()->render_quad(target, glm::zero<glm::vec2>(), SCREEN_ORTHO_MAT4, g_sample);
            g_sample += 1.0f;
        }

        g_time += t_delta;

        App::inst()->present();
    }

    App::inst()->destroy();

    return 0;
}
