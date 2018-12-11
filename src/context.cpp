#include <stdexcept>
#include <GL/glew.h>
#include <context.hpp>

Context::Context()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 4;
    settings.minorVersion = 5;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.attributeFlags = sf::ContextSettings::Attribute::Core;

    window.create(
        {1280, 720},
        "Minecraft",
        sf::Style::Close,
        settings);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        throw std::runtime_error("Unable to init glew!");

    glViewport(0, 0, 1280, 720);

    window.setFramerateLimit(60);
}