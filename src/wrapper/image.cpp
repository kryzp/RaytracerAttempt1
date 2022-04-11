#include "image.h"
#include <memory>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Image::Image()
    : m_pixels(nullptr)
    , m_width(0)
    , m_height(0)
    , m_nr_channels(0)
    , m_stbi_management(false)
{
}

Image::Image(const std::string& path)
{
    load(path);
}

Image::Image(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_nr_channels(0)
    , m_stbi_management(false)
{
    m_pixels = new unsigned char[width * height];
}

Image::~Image()
{
    free();
}

void Image::load(const std::string& path)
{
    m_stbi_management = true;

    stbi_set_flip_vertically_on_load(true);

    int w, h, nrc;
    m_pixels = stbi_load(path.c_str(), &w, &h, &nrc, 0);
    m_width = w;
    m_height = h;
    m_nr_channels = nrc;
}

void Image::free()
{
    if (!m_pixels)
        return;

    if (m_stbi_management)
        stbi_image_free(m_pixels);
    else
        delete[] m_pixels;

    m_pixels = nullptr;
}

void Image::pixels(const unsigned char* data)
{
    memcpy(m_pixels, data, sizeof(unsigned char) * (m_width * m_height));
}

void Image::pixels(const unsigned char* data, GLuint64 pixel_count)
{
    memcpy(m_pixels, data, sizeof(unsigned char) * pixel_count);
}

void Image::pixels(const unsigned char* data, GLuint64 offset, GLuint64 pixel_count)
{
    memcpy(m_pixels, data + offset, sizeof(unsigned char) * pixel_count);
}

unsigned char* Image::pixels()
{
    return m_pixels;
}

const unsigned char* Image::pixels() const
{
    return m_pixels;
}

int Image::width() const
{
    return m_width;
}

int Image::height() const
{
    return m_height;
}

int Image::nr_channels() const
{
    return m_nr_channels;
}
