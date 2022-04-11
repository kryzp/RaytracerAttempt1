#pragma once

#include <unordered_map>
#include <string>

#include "texture.h"

class TextureMgr
{
public:
    static TextureMgr* inst()
    {
        static TextureMgr* instance = nullptr;
        if (!instance) { instance = new TextureMgr(); }
        return instance;
    }

    void load_textures();
    void add_texture(const std::string& name, const std::string& path, GLenum format, GLenum internal_format, GLenum type);
    Texture& get_texture(const std::string& name);

private:
    std::unordered_map<std::string, Texture> m_textures;
};
