#ifndef SHADERS_SHADER_LOADER_HPP
#define SHADERS_SHADER_LOADER_HPP
#include <string>
#include <glad/glad.h>

GLuint load_shaders(
    const std::string &vertex_shader,
    const std::string &fragment_shader);

#endif