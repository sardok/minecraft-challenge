#include <stdexcept>
#include <texture/texture_atlas.hpp>

TextureAtlas::TextureAtlas(const std::string &texture_filename)
{
    sf::Image img;
    if (!img.loadFromFile("res/textures/" + texture_filename + ".png"))
        throw std::runtime_error("Unable to open image: " + texture_filename);

    load_from_image(img);

    image_size = 256;
    individual_texture_size = 16;
}

std::vector<GLfloat> TextureAtlas::get_texture(const sf::Vector2i &coords)
{
    static const GLfloat TEX_PER_ROW = (GLfloat)image_size / (GLfloat)individual_texture_size;
    static const GLfloat INDV_TEX_SIZE = 1.0f / TEX_PER_ROW;
    static const GLfloat PIXEL_SIZE = 1.0f / (float)image_size;

    GLfloat xMin = (coords.x * INDV_TEX_SIZE) + 0.5 * PIXEL_SIZE;
    GLfloat yMin = (coords.y * INDV_TEX_SIZE) + 0.5 * PIXEL_SIZE;

    GLfloat xMax = (xMin + INDV_TEX_SIZE) - 0.5 * PIXEL_SIZE;
    GLfloat yMax = (yMin + INDV_TEX_SIZE) - 0.5 * PIXEL_SIZE;

    return {
        xMax, yMax,
        xMin, yMax,
        xMin, yMin,
        xMax, yMin};
}