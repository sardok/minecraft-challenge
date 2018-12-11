#include <shaders/shader.hpp>
#include <shaders/shader_loader.hpp>

Shader::Shader(
    const std::string &vertex_file,
    const std::string &fragment_file)
    : id(load_shaders(vertex_file, fragment_file))
{
    use_program();
}

void Shader::use_program() const
{
    glUseProgram(id);
}

void Shader::load_int(GLuint location, int value)
{
    glUniform1i(location, value);
}

void Shader::load_float(GLuint location, int value)
{
    glUniform1f(location, value);
}

void Shader::load_vector2(GLuint location, const Vector2 &vector)
{
    glUniform2f(location, vector.x, vector.y);
}

void Shader::load_vector3(GLuint location, const Vector3 &vector)
{
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void Shader::load_vector4(GLuint location, const Vector4 &vector)
{
    glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
}

void Shader::load_matrix4(GLuint location, const Matrix4 &matrix)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

Shader::~Shader()
{
    glDeleteProgram(id);
}
