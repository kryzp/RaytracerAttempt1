#include "texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_id);
}

void Texture::create(int width, int height, GLenum format, GLenum internal_format, GLenum type, const unsigned char* data)
{
    m_id = 0;

    m_width = width;
    m_height = height;
    m_format = format;
    m_internal_format = internal_format;
    m_type = type;

    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, m_internal_format, m_width, m_height, 0, m_format, m_type, data);
    this->update(GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR);
}

void Texture::load(const Image& image, GLenum format, GLenum internal_format, GLenum type)
{
    create(image.width(), image.height(), format, internal_format, type, image.pixels());
}

void Texture::bind(int idx) const
{
    glActiveTexture(GL_TEXTURE0 + idx);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::bind_image(int idx) const
{
    glActiveTexture(GL_TEXTURE0 + idx);
    glBindImageTexture(idx, m_id, 0, GL_FALSE, 0, GL_READ_WRITE, m_internal_format);
}

void Texture::generate(const void* data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, m_internal_format, m_width, m_height, 0, m_format, m_type, data);
}

void Texture::get_data(float* buf)
{
    glGetTexImage(GL_TEXTURE_2D, 0, m_format, m_type, buf);
}

void Texture::update(GLenum wrap, GLenum min, GLenum mag)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag);
}

int Texture::width() const
{
    return m_width;
}

int Texture::height() const
{
    return m_height;
}

GLenum Texture::format() const
{
    return m_format;
}

GLenum Texture::internal_format() const
{
    return m_internal_format;
}

GLenum Texture::type() const
{
    return m_type;
}

GLuint Texture::texture() const
{
    return m_id;
}
