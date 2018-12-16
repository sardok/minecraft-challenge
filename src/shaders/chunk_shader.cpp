#include <shaders/chunk_shader.hpp>

ChunkShader::ChunkShader()
    : BasicShader("chunk_vertex", "chunk_fragment")
{
    get_uniforms();
}

void ChunkShader::get_uniforms()
{
    BasicShader::get_uniforms();
}