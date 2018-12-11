#include <renderer/render_master.hpp>

void RenderMaster::draw_quad(const Vector3 &pos)
{
    quad_renderer.add(pos);
}

void RenderMaster::finish_render(sf::RenderWindow &window, const Camera &camera)
{
    glClearColor(0.1, 0.5, 1.0, 1.0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    quad_renderer.render_quads(camera);

    window.display();
}