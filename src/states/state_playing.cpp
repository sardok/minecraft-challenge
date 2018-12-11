#include <states/state_playing.hpp>
#include <application.hpp>
#include <renderer/render_master.hpp>

StatePlaying::StatePlaying(Application &application)
    : StateBase(application)
{
    application.get_camera().hook_entity(player);
}

void StatePlaying::handle_event(sf::Event evt)
{
}

void StatePlaying::handle_input()
{
    player.handle_input(app->get_window());
}

void StatePlaying::update(float delta_time)
{
    player.update(delta_time);
}

void StatePlaying::render(RenderMaster &renderer)
{
    renderer.draw_quad({0, 0, 0});
}