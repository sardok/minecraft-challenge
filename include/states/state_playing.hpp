#ifndef STATES_STATE_PLAYING_HPP
#define STATES_STATE_PLAYING_HPP
#include <states/state_base.hpp>
#include <player/player.hpp>

class StatePlaying : public StateBase
{
  public:
    StatePlaying(Application &application);

    void handle_event(sf::Event evt);
    void handle_input();

    void update(float delta_time);
    void render(RenderMaster &renderer);

  protected:
    Player player;
};
#endif