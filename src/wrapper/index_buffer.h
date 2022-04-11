#pragma once

#include <glad/glad.h>

class IndexBuffer
{
public:
    IndexBuffer();
    ~IndexBuffer();

    IndexBuffer& bind();
    void unbind();

    IndexBuffer& buffer_data(GLsizei size, const void* data, GLenum usage);

private:
    GLuint m_id;
};
