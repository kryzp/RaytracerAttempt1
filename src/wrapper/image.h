#pragma once

#include <functional>
#include <glad/glad.h>
#include <string>

class Image
{
public:
    Image();
    Image(const std::string& path);
    Image(int width, int height);
    ~Image();

    void load(const std::string& path);
    void free();

    void pixels(const unsigned char* data);
    void pixels(const unsigned char* data, GLuint64 pixel_count);
    void pixels(const unsigned char* data, GLuint64 offset, GLuint64 pixel_count);

    unsigned char* pixels();
    const unsigned char* pixels() const;

    int width() const;
    int height() const;
    int nr_channels() const;

private:
    unsigned char* m_pixels;

    int m_width;
    int m_height;
    int m_nr_channels;

    bool m_stbi_management;
};
