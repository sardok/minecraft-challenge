#ifndef MODEL_HPP
#define MODEL_HPP
#include <vector>
#include <glad/glad.h>
#include <utils/non_copyable.hpp>
#include <mesh.hpp>

class Model : public NonCopyable
{
  public:
    Model() = default;
    Model(const Mesh &mesh);
    ~Model();

    void add_data(const Mesh &mesh);

    void delete_data();

    void add_vbo(int dimensions, const std::vector<GLfloat> &data);
    void bind_vao() const;

    int get_indices_count() const;

  private:
    void add_ebo(const std::vector<GLuint> &indices);

    GLuint vao = 0;
    int vbo_count = 0;
    int indices_count = 0;
    std::vector<GLuint> buffers;
};
#endif