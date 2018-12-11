#ifndef RENDER_MASTER_HPP
#define RENDER_MASTER_HPP
#include <SFML/Graphics.hpp>
#include <maths/glm.hpp>
#include "quad_renderer.hpp"

class Camera;

class RenderMaster
{
public:
  void draw_quad(const Vector3 &pos);
  void finish_render(sf::RenderWindow &window, const Camera &camera);

private:
  QuadRenderer quad_renderer;
};
#endif