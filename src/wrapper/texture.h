#pragma once

#include <glad/glad.h>
#include "image.h"

class Texture
{
    GLuint m_id;

    GLenum m_format;
    GLenum m_internal_format;
    GLenum m_type;

    int m_width;
    int m_height;

public:
    Texture();
    ~Texture();

    void load(const Image& image, GLenum format, GLenum internal_format, GLenum type);
    void create(int width, int height, GLenum format, GLenum internal_format, GLenum type, const unsigned char* data);

    void bind(int idx) const;
    void bind_image(int idx) const;

    void generate(const void* data);
    void get_data(float* buf);
    void update(GLenum wrap, GLenum min, GLenum mag);

    int width() const;
    int height() const;
    GLenum format() const;
    GLenum internal_format() const;
    GLenum type() const;
    GLuint texture() const;
};
