#pragma once

#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer();
    ~VertexBuffer();

    VertexBuffer& bind();
    void unbind();

    VertexBuffer& vertex_attrib_pointer(GLuint idx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);
    VertexBuffer& buffer_data(GLsizei size, const void* data, GLenum usage);

    GLuint buffer();

private:
    GLuint m_id;
};
