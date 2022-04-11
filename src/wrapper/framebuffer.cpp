#include "framebuffer.h"

Framebuffer::Framebuffer()
{
}

Framebuffer::Framebuffer(int width, int height, const std::vector<AttachmentFormat>& format)
{
    create(width, height, format);
}

Framebuffer::~Framebuffer()
{
    glDeleteFramebuffers(1, &m_id);
}

void Framebuffer::create(int width, int height, const std::vector<AttachmentFormat>& format)
{
    m_id = 0;
    m_width = width;
    m_height = height;
    m_format = format;

    glGenFramebuffers(1, &m_id);
    glBindFramebuffer(GL_FRAMEBUFFER, m_id);

    for (int i = 0; i < format.size(); i++)
    {
        const auto& fmt = format[i];

        GLuint texture = 0;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, fmt.format, width, height, 0, fmt.internal_format, fmt.type, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, fmt.min);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, fmt.mag);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, fmt.wrap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, fmt.wrap);

        if (fmt.format == GL_DEPTH_STENCIL)
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texture, 0);
        else
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, texture, 0);

        m_texture_attachments.push_back(texture);
    }
}

void Framebuffer::bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_id);
}

void Framebuffer::clear(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    bind();
    glViewport(0, 0, m_width, m_height);
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

const std::vector<GLuint>& Framebuffer::attachments() const
{
    return m_texture_attachments;
}

GLuint Framebuffer::attachment(int idx)
{
    return m_texture_attachments[idx];
}

const std::vector<Framebuffer::AttachmentFormat>& Framebuffer::format() const
{
    return m_format;
}

int Framebuffer::width() const
{
    return m_width;
}

int Framebuffer::height() const
{
    return m_height;
}

GLuint Framebuffer::fbo() const
{
    return m_id;
}
