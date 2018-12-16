#ifndef CHUNK_RENDERER_HPP
#define CHUNK_RENDERER_HPP
#include <vector>
#include <shaders/chunk_shader.hpp>

class ChunkMesh;
class Camera;

class ChunkRenderer
{
  public:
    void add(const ChunkMesh &mesh);
    void render(const Camera &camera);

  private:
    std::vector<const ChunkMesh *> chunks;
    ChunkShader shader;
};
#endif