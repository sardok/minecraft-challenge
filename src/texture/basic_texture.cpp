#include <iostream>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <texture/basic_texture.hpp>

BasicTexture::BasicTexture(const std::string &file)
{
    load_from_file(file);
}

BasicTexture::~BasicTexture()
{
    glDeleteTextures(1, &id);
}

void BasicTexture::load_from_file(const std::string &file)
{
    sf::Image img;
    if (!img.loadFromFile("res/textures/" + file + ".png"))
    {
        throw std::runtime_error("Unable to load " + file);
    }

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        img.getSize().x,
        img.getSize().y,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        img.getPixelsPtr());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void BasicTexture::bind_texture() const
{
    glBindTexture(GL_TEXTURE_2D, id);
}