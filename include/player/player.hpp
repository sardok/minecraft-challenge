#ifndef PLAYER_PLAYER_HPP
#define PLAYER_PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <entity.hpp>
#include <maths/glm.hpp>
#include <entity.hpp>

class Player : public Entity
{
  public:
    Player();

    void handle_input(const sf::RenderWindow &window);
    void update(float delta_time);

  private:
    void keyboard_input();
    void mouse_input(const sf::RenderWindow &window);
    Vector3 velocity;
};
#endif