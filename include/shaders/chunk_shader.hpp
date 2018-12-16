#ifndef CHUNK_SHADER_HPP
#define CHUNK_SHADER_HPP

#include <shaders/basic_shader.hpp>

class ChunkShader : public BasicShader
{
  public:
    ChunkShader();

  private:
    void get_uniforms() override;
};
#endif