#ifndef TEXTURE_ATLAS_HPP
#define TEXTURE_ATLAS_HPP
#include <vector>
#include <SFML/Graphics.hpp>
#include "basic_texture.hpp"

class TextureAtlas : public BasicTexture
{
  public:
    TextureAtlas(const std::string &texture_filename);
    std::vector<GLfloat> get_texture(const sf::Vector2i &coords);

  private:
    int image_size;
    int individual_texture_size;
};
#endif