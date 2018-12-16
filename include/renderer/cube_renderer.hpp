#ifndef CUBE_RENDERER_HPP
#define CUBE_RENDERER_HPP
#include <vector>
#include <model.hpp>
#include <shaders/basic_shader.hpp>
#include <texture/basic_texture.hpp>
#include <texture/texture_atlas.hpp>
#include <maths/matrix.hpp>

class Camera;

class CubeRenderer
{
  public:
    CubeRenderer();
    void add(const Vector3 &pos);
    void render(const Camera &camera);

  private:
    std::vector<Vector3> quads;
    Model cube_model;
    BasicShader shader;
    BasicTexture texture;
    TextureAtlas atlas_test;
};
#endif