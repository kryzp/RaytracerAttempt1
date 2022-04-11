#pragma once

#include <glad/glad.h>

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    VertexArray& bind();
    void unbind();

private:
    GLuint m_id;
};
