#include <iostream>
#include <shaders/basic_shader.hpp>

BasicShader::BasicShader(
    const std::string &vertex_file,
    const std::string &fragment_file)
    : Shader(vertex_file, fragment_file)
{
    get_uniforms();
}

void BasicShader::load_projection_view_matrix(const Matrix4 &matrix)
{
    load_matrix4(location_projection_view_matrix, matrix);
}

void BasicShader::load_model_matrix(const Matrix4 &matrix)
{
    load_matrix4(location_model_matrix, matrix);
}

void BasicShader::get_uniforms()
{
    use_program();
    location_projection_view_matrix = glGetUniformLocation(id, "projViewMatrix");
    location_model_matrix = glGetUniformLocation(id, "modelMatrix");
}