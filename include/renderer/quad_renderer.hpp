#ifndef RENDERER_QUAD_RENDERER_HPP
#define RENDERER_QUAD_RENDERER_HPP
#include <vector>
#include <maths/glm.hpp>
#include <shaders/basic_shader.hpp>
#include <texture/basic_texture.hpp>
#include <model.hpp>

class Camera;

class QuadRenderer
{
  public:
    QuadRenderer();

    void add(const Vector3 &position);
    void render_quads(const Camera &camera);

  private:
    std::vector<Vector3> quads;
    Model quad_model;
    BasicShader shader;
    BasicTexture texture;
};
#endif