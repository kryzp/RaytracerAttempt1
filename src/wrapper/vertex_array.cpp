#include "vertex_array.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_id);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_id);
}

VertexArray& VertexArray::bind()
{
    glBindVertexArray(m_id);
    return *this;
}

void VertexArray::unbind()
{
    glBindVertexArray(0);
}
