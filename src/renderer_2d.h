#pragma once

#include <glm/vec2.hpp>

#include "wrapper/shader.h"
#include "wrapper/texture.h"
#include "wrapper/index_buffer.h"
#include "wrapper/vertex_buffer.h"
#include "wrapper/vertex_array.h"

class Renderer2D
{
public:
    static Renderer2D* inst()
    {
        static Renderer2D* instance = nullptr;
        if (!instance) { instance = new Renderer2D(); }
        return instance;
    }

    void init();

    void render_quad(const Texture& tex, const glm::vec2& position, const glm::mat4& projection, float sample);

private:
    Shader* m_default_shader;

    VertexArray m_vao;
    VertexBuffer m_vbo;
    IndexBuffer m_ibo;
};
