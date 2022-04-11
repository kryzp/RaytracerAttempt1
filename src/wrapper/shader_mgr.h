#pragma once

#include <unordered_map>
#include <string>

#include "shader.h"

class ShaderMgr
{
public:
    static ShaderMgr* inst()
    {
        static ShaderMgr* instance = nullptr;
        if (!instance) { instance = new ShaderMgr(); }
        return instance;
    }

    void load_shaders();

    void add_shader(const std::string& name, const std::string& vertex_path, const std::string& fragment_path, const std::string& geometry_path = "");
    void add_compute_shader(const std::string& name, const std::string& compute_path);

    Shader& get_shader(const std::string& name);

private:
    std::unordered_map<std::string, Shader> m_shaders;
};
