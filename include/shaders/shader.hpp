#ifndef SHADERS_SHADER_HPP
#define SHADERS_SHADER_HPP
#include <string>
#include <glad/glad.h>
#include <maths/glm.hpp>
#include <utils/non_copyable.hpp>

class Shader : NonCopyable
{
public:
  Shader(const std::string &vertex_file, const std::string &fragment_file);
  ~Shader();

  void use_program() const;

  void load_int(GLuint location, int value);
  void load_float(GLuint location, int value);

  void load_vector2(GLuint location, const Vector2 &vector);
  void load_vector3(GLuint location, const Vector3 &vector);
  void load_vector4(GLuint location, const Vector4 &vector);

  void load_matrix4(GLuint location, const Matrix4 &matrix);

protected:
  virtual void get_uniforms() = 0;
  GLuint id;
};
#endif