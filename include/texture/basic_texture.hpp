#ifndef TEXTURE_BASIC_TEXTURE_HPP
#define TEXTURE_BASIC_TEXTURE_HPP
#include <string>
#include <GL/glew.h>

class BasicTexture
{
  public:
    BasicTexture() = default;
    BasicTexture(const std::string &file);

    ~BasicTexture();

    void load_from_file(const std::string &file);
    void bind_texture() const;

  private:
    GLuint id;
};
#endif