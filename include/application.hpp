#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <states/state_base.hpp>
#include <camera.hpp>
#include <context.hpp>
#include <renderer/render_master.hpp>

class Application
{
  public:
    Application(std::string &&name);
    void run_loop();

    template <typename T, typename... Args>
    void push_state(Args &&... args)
    {
        states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        auto &s = states.back();
    }

    void pop_state();

    Camera &get_camera()
    {
        return camera;
    }

    const sf::RenderWindow &get_window() const
    {
        return context.window;
    }

  private:
    void handle_events();
    std::vector<std::unique_ptr<StateBase>> states;
    Context context;
    Camera camera;
    RenderMaster renderer;
    bool is_pop_state = false;
};

#endif