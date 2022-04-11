#pragma once

#include <vector>
#include <glad/glad.h>

class Framebuffer
{
public:
    struct AttachmentFormat
    {
        GLenum format;
        GLenum internal_format;
        GLenum type;
        GLenum min;
        GLenum mag;
        GLenum wrap;
    };

    Framebuffer();
    Framebuffer(int width, int height, const std::vector<AttachmentFormat>& format);
    ~Framebuffer();

    void create(int width, int height, const std::vector<AttachmentFormat>& format);

    void bind() const;
    void clear(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    const std::vector<GLuint>& attachments() const;
    GLuint attachment(int idx);

    const std::vector<AttachmentFormat>& format() const;

    int width() const;
    int height() const;
    GLuint fbo() const;

private:
    GLuint m_id;

    std::vector<AttachmentFormat> m_format;
    std::vector<GLuint> m_texture_attachments;

    int m_width;
    int m_height;
};
