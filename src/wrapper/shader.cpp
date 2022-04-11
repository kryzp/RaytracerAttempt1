#include "shader.h"
#include <iostream>

ShaderBuffer::ShaderBuffer()
    : m_id(0)
    , m_size(0)
{
}

ShaderBuffer::ShaderBuffer(GLsizeiptr size)
    : m_id(0)
    , m_size(size)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_id);
    glBufferData(GL_SHADER_STORAGE_BUFFER, size, nullptr, GL_DYNAMIC_COPY);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

ShaderBuffer::~ShaderBuffer()
{
    release();
}

void ShaderBuffer::create(GLsizeiptr size)
{
    m_size = size;

    glGenBuffers(1, &m_id);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_id);
    glBufferData(GL_SHADER_STORAGE_BUFFER, size, nullptr, GL_DYNAMIC_COPY);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void ShaderBuffer::set(void* buf) const
{
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_id);
    void* p = glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_WRITE_ONLY);
    memcpy(p, buf, m_size);
    glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
}

void ShaderBuffer::release() const
{
    glDeleteBuffers(1, &m_id);
}

void ShaderBuffer::bind(int idx) const
{
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, idx, m_id);
}

GLuint ShaderBuffer::buffer() const
{
    return m_id;
}

GLuint64 ShaderBuffer::size() const
{
    return m_size;
}

///////////////////////////////////////////////////////

Shader::Shader()
    : m_id(0)
{
}

Shader::~Shader()
{
    glDeleteProgram(m_id);
}

void Shader::compile_compute(const std::string& computesrc)
{
    int success;
    char infolog[512];

    const char* computedata = computesrc.c_str();

    GLuint id = glCreateProgram();

    GLuint compute = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(compute, 1, &computedata, NULL);
    glCompileShader(compute);
    glAttachShader(id, compute);

    glLinkProgram(id);

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(id, 512, NULL, infolog);
        std::cout << "failed to link compute shader program: " << infolog << std::endl;
    }

    glDeleteShader(compute);

    m_id = id;
}

void Shader::compile(const std::string& vertexsrc, const std::string& fragmentsrc, const std::string& geometrysrc)
{
    int success;
    char infolog[512];

    const char* vertexdata = vertexsrc.c_str();
    const char* fragmentdata = fragmentsrc.c_str();
    const char* geometrydata = geometrysrc.c_str();

    GLuint id = glCreateProgram();

    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexdata, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infolog);
        std::cout << "failed to compile vertex shader: %s" << infolog << std::endl;
    }

    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentdata, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infolog);
        std::cout << "failed to compile fragment shader: " << infolog << std::endl;
    }

    GLuint geometry = 0;
    if (!geometrysrc.empty())
    {
        geometry = glCreateShader(GL_GEOMETRY_SHADER);

        glShaderSource(geometry, 1, &geometrydata, NULL);
        glCompileShader(geometry);

        glGetShaderiv(geometry, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(geometry, 512, NULL, infolog);
            std::cout << "failed to compile geometry shader: " << infolog  << std::endl;
        }
    }

    glAttachShader(id, vertex);
    glAttachShader(id, fragment);

    if (!geometrysrc.empty())
        glAttachShader(id, geometry);

    glLinkProgram(id);

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(id, 512, NULL, infolog);
        std::cout << "failed to link rendering shader program: " << infolog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    if (!geometrysrc.empty())
        glDeleteShader(geometry);

    m_id = id;
}

Shader& Shader::dispatch_compute(GLuint n_groups_x, GLuint n_groups_y, GLuint n_groups_z)
{
    glDispatchCompute(n_groups_x, n_groups_y, n_groups_z);
    return *this;
}

Shader& Shader::dispatch_compute(GLintptr indirect)
{
    glDispatchComputeIndirect(indirect);
    return *this;
}

Shader& Shader::wait_compute()
{
    glMemoryBarrier(GL_ALL_BARRIER_BITS);
    return *this;
}

Shader& Shader::use()
{
    glUseProgram(m_id);
    return *this;
}

Shader& Shader::set_buffer(const ShaderBuffer& buf, int binding)
{
    buf.bind(binding);
    return *this;
}

GLuint Shader::shader() const
{
    return m_id;
}

Shader& Shader::set_bool(const char* name, GLboolean value)
{
    glUniform1i(get_uniform_location(name), value);
    return *this;
}

Shader& Shader::set_int(const char* name, GLint value)
{
    glUniform1i(get_uniform_location(name), value);
    return *this;
}

Shader& Shader::set_float(const char* name, GLfloat value)
{
    glUniform1f(get_uniform_location(name), value);
    return *this;
}

Shader& Shader::set_vec2i(const char* name, const glm::ivec2& value)
{
    glUniform2i(get_uniform_location(name), value.x, value.y);
    return *this;
}

Shader& Shader::set_vec2f(const char* name, const glm::vec2& value)
{
    glUniform2f(get_uniform_location(name), value.x, value.y);
    return *this;
}

Shader& Shader::set_vec3i(const char* name, const glm::ivec3& value)
{
    glUniform3i(get_uniform_location(name), value.x, value.y, value.z);
    return *this;
}

Shader& Shader::set_vec3f(const char* name, const glm::vec3& value)
{
    glUniform3f(get_uniform_location(name), value.x, value.y, value.z);
    return *this;
}

Shader& Shader::set_vec4i(const char* name, const glm::ivec4& value)
{
    glUniform4i(get_uniform_location(name), value.x, value.y, value.z, value.w);
    return *this;
}

Shader& Shader::set_vec4f(const char* name, const glm::vec4& value)
{
    glUniform4f(get_uniform_location(name), value.x, value.y, value.z, value.w);
    return *this;
}

Shader& Shader::set_mat3(const char* name, const glm::mat3& value)
{
    glUniformMatrix3fv(get_uniform_location(name), 1, GL_FALSE, glm::value_ptr(value));
    return *this;
}

Shader& Shader::set_mat4(const char* name, const glm::mat4& value)
{
    glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, glm::value_ptr(value));
    return *this;
}

GLint Shader::get_uniform_location(const char* name)
{
    if (!m_locations.contains(name))
        m_locations.insert(std::make_pair(name, glGetUniformLocation(m_id, name)));
    return m_locations.at(name);
}
