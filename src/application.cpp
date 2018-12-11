#include <application.hpp>
#include <states/state_playing.hpp>

Application::Application(std::string &&name)
{
    push_state<StatePlaying>(*this);
}

void Application::run_loop()
{
    sf::Clock dt_timer;

    while (context.window.isOpen() && !states.empty())
    {
        auto delta_time = dt_timer.restart();
        auto &state = *states.back();

        state.handle_input();
        state.update(delta_time.asSeconds());
        camera.update();

        state.render(renderer);
        renderer.finish_render(context.window, camera);

        handle_events();
        if (is_pop_state)
        {
            is_pop_state = false;
            states.pop_back();
        }
    }
}

void Application::handle_events()
{
    sf::Event evt;
    while (context.window.pollEvent(evt))
    {
        switch (evt.type)
        {
        case sf::Event::Closed:
            context.window.close();
            break;
        case sf::Event::KeyPressed:
            switch (evt.key.code)
            {
            case sf::Keyboard::Escape:
                context.window.close();
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
}

void Application::pop_state()
{
    is_pop_state = true;
}