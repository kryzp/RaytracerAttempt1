#include "texture_mgr.h"

void TextureMgr::load_textures()
{
    add_texture("SKYBOX", "D:\\_PROJECTS\\RayTracingOneWeekend\\res\\textures\\sunset_at_pier.jpg", GL_RGB, GL_RGBA32F, GL_UNSIGNED_BYTE);
}

void TextureMgr::add_texture(const std::string& name, const std::string& path, GLenum format, GLenum internal_format, GLenum type)
{
    m_textures.emplace(name, Texture());
    m_textures.at(name).load(Image(path), format, internal_format, type);
}

Texture& TextureMgr::get_texture(const std::string& name)
{
    return m_textures.at(name);
}
