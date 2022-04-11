#include "vertex_buffer.h"

VertexBuffer::VertexBuffer()
{
    glGenBuffers(1, &m_id);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_id);
}

VertexBuffer& VertexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    return *this;
}

void VertexBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer& VertexBuffer::vertex_attrib_pointer(GLuint idx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr)
{
    glVertexAttribPointer(idx, size, type, normalized, stride, ptr);
    glEnableVertexAttribArray(idx);
    return *this;
}

VertexBuffer& VertexBuffer::buffer_data(GLsizei size, const void* data, GLenum usage)
{
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    return *this;
}

GLuint VertexBuffer::buffer()
{
    return m_id;
}
