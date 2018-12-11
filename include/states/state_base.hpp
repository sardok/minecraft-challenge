#ifndef STATES_STATE_BASE_HPP
#define STATES_STATE_BASE_HPP
#include <SFML/Graphics.hpp>

class RenderMaster;
class Application;

class StateBase
{
public:
  StateBase(Application &application) : app(&application)
  {
  }

  virtual ~StateBase() noexcept = default;
  virtual void handle_event(sf::Event evt) = 0;
  virtual void handle_input() = 0;
  virtual void update(float delta_time) = 0;
  virtual void render(RenderMaster &renderer) = 0;

protected:
  Application *app;
};
#endif