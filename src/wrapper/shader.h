#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>

class ShaderBuffer
{
    GLuint m_id;
    GLsizeiptr m_size;

public:
    ShaderBuffer();
    ShaderBuffer(GLsizeiptr size);
    ~ShaderBuffer();

    void create(GLsizeiptr size);
    void set(void* buf) const;
    void release() const;

    void bind(int idx) const;

    GLuint buffer() const;
    GLuint64 size() const;
};

class Shader
{
public:
    Shader();
    ~Shader();

    void compile(const std::string& vertexdata, const std::string& fragmentdata, const std::string& geometrydata);
    void compile_compute(const std::string& computedata);

    Shader& dispatch_compute(GLuint n_groups_x, GLuint n_groups_y, GLuint n_groups_z);
    Shader& dispatch_compute(GLintptr indirect);
    Shader& wait_compute();

    Shader& use();
    Shader& set_buffer(const ShaderBuffer& buf, int binding);

    GLuint shader() const;

    Shader& set_bool(const char* name, GLboolean value);
    Shader& set_int(const char* name, GLint value);
    Shader& set_float(const char* name, GLfloat value);
    Shader& set_vec2i(const char* name, const glm::ivec2& value);
    Shader& set_vec2f(const char* name, const glm::vec2& value);
    Shader& set_vec3i(const char* name, const glm::ivec3& value);
    Shader& set_vec3f(const char* name, const glm::vec3& value);
    Shader& set_vec4i(const char* name, const glm::ivec4& value);
    Shader& set_vec4f(const char* name, const glm::vec4& value);
    Shader& set_mat3(const char* name, const glm::mat3& value);
    Shader& set_mat4(const char* name, const glm::mat4& value);

private:
    GLint get_uniform_location(const char* name);
    std::unordered_map<std::string, GLint> m_locations;

    GLuint m_id;
};
