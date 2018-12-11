#include <stdexcept>
#include <iostream>
#include <shaders/shader_loader.hpp>
#include <utils/file_utils.hpp>

namespace
{

GLuint compile_shader(const GLchar *source, GLenum shader_type)
{
    auto shader_id = glCreateShader(shader_type);
    glShaderSource(shader_id, 1, &source, nullptr);
    glCompileShader(shader_id);

    GLint success = 0;
    GLchar info_log[512];

    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader_id, 512, nullptr, info_log);
        throw std::runtime_error("Unable to load a shader: " + std::string(info_log));
    }

    return shader_id;
}

GLuint link_program(GLuint vertex_shader_id, GLuint fragment_shader_id)
{
    auto id = glCreateProgram();

    glAttachShader(id, vertex_shader_id);
    glAttachShader(id, fragment_shader_id);

    glLinkProgram(id);

    return id;
}

void check_link_success(GLuint shader_id)
{
    GLint success = 0;
    GLchar info_log[512];
    glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader_id, 512, nullptr, info_log);
        throw std::runtime_error("Failed shader linking: " + std::string(info_log));
    }
}
} // namespace

GLuint load_shaders(
    const std::string &vertex_shader,
    const std::string &fragment_shader)
{
    auto vertex_source = get_file_contents("shaders/" + vertex_shader + ".glsl");
    auto fragment_source = get_file_contents("shaders/" + fragment_shader + ".glsl");

    auto vertex_shader_id = compile_shader(vertex_source.c_str(), GL_VERTEX_SHADER);
    auto fragment_shader_id = compile_shader(fragment_source.c_str(), GL_FRAGMENT_SHADER);

    auto shader_id = link_program(vertex_shader_id, fragment_shader_id);
    check_link_success(shader_id);

    glDetachShader(shader_id, vertex_shader_id);
    glDetachShader(shader_id, fragment_shader_id);

    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);

    return shader_id;
}