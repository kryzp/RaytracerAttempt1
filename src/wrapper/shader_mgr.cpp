#include "shader_mgr.h"

#include <fstream>
#include <sstream>

void ShaderMgr::load_shaders()
{
    add_compute_shader("C_RAYTRACE",
        "D:\\_PROJECTS\\RayTracingOneWeekend\\res\\shaders\\raytrace.comp"
    );

    add_shader("DEFAULT2D",
        "D:\\_PROJECTS\\RayTracingOneWeekend\\res\\shaders\\default_2d.vert",
        "D:\\_PROJECTS\\RayTracingOneWeekend\\res\\shaders\\default_2d.frag"
    );
}

void ShaderMgr::add_shader(const std::string& name, const std::string& vertex_path, const std::string& fragment_path, const std::string& geometry_path)
{
    std::string vertex_data, fragment_data, geometry_data;
    std::stringstream buf;

    // vertex
    {
        buf.str("");
        std::ifstream vertex_file(vertex_path);
        buf << vertex_file.rdbuf();
        vertex_data = buf.str();
    }

    // fragment
    {
        buf.str("");
        std::ifstream fragment_file(fragment_path);
        buf << fragment_file.rdbuf();
        fragment_data = buf.str();
    }

    // geometry
    if (!geometry_path.empty())
    {
        buf.str("");
        std::ifstream geometry_file(geometry_path);
        buf << geometry_file.rdbuf();
        geometry_data = buf.str();
    }

    m_shaders.emplace(name, Shader());
    m_shaders.at(name).compile(vertex_data, fragment_data, geometry_data);
}

void ShaderMgr::add_compute_shader(const std::string& name, const std::string& compute_path)
{
    Shader shader;

    std::string compute_data;
    std::stringstream buf;

    std::ifstream compute_file(compute_path);
    buf << compute_file.rdbuf();
    compute_data = buf.str();

    m_shaders.emplace(name, Shader());
    m_shaders.at(name).compile_compute(compute_data);
}

Shader& ShaderMgr::get_shader(const std::string& name)
{
    return m_shaders.at(name);
}
