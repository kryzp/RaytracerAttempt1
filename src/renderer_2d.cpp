#include "renderer_2d.h"
#include "wrapper/shader_mgr.h"

void Renderer2D::init()
{
    static const GLuint indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    m_vao.bind();
    {
        m_vbo.bind();
        m_vbo.vertex_attrib_pointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, (void*)(0 * sizeof(GLfloat)));
        m_vbo.vertex_attrib_pointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(2 * sizeof(GLfloat)));

        m_ibo.bind();
        m_ibo.buffer_data(6 * sizeof(GLuint), indices, GL_STATIC_DRAW);
    }
    m_vao.unbind();

    m_default_shader = &ShaderMgr::inst()->get_shader("DEFAULT2D");
}

void Renderer2D::render_quad(const Texture& tex, const glm::vec2& position, const glm::mat4& projection, float sample)
{
    float x1 = position.x;
    float y1 = position.y;
    float x2 = position.x + tex.width();
    float y2 = position.y + tex.height();

    const GLfloat vertices[] {
        x2, y2, 1.0f, 1.0f,
        x2, y1, 1.0f, 0.0f,
        x1, y1, 0.0f, 0.0f,
        x1, y2, 0.0f, 1.0f
    };

    tex.bind(0);

    m_default_shader->use()
        .set_float("u_sample", sample)
        .set_mat4("u_projection", projection)
        .set_int("u_texture", 0);

    m_vao.bind();
    m_vbo.buffer_data(16 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    m_vao.unbind();
}
