#ifndef SHADERS_BASIC_SHADER_HPP
#define SHADERS_BASIC_SHADER_HPP
#include <string>
#include <shaders/shader.hpp>
#include <maths/glm.hpp>

class BasicShader : public Shader
{
  public:
    BasicShader(
        const std::string &vertex_file = "basic_vertex",
        const std::string &fragment_file = "basic_fragment");

    void load_projection_view_matrix(const Matrix4 &matrix);
    void load_model_matrix(const Matrix4 &matrix);

  private:
    virtual void get_uniforms() override;

    GLuint location_projection_view_matrix;
    GLuint location_model_matrix;
};
#endif