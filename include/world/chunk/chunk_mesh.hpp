#ifndef CHUNK_MESH_HPP
#define CHUNK_MESH_HPP
#include <vector>
#include <SFML/Graphics.hpp>
#include <model.hpp>

class ChunkMesh
{
  public:
    ChunkMesh();

    void add_face(
        const std::vector<GLfloat> &block_face,
        const std::vector<GLfloat> &texture_coords,
        const sf::Vector3i &chunk_position,
        const sf::Vector3i &block_position);

    void buffer_mesh();
    const Model &get_model() const;

  private:
    Mesh mesh;
    Model model;
    GLuint index_index = 0;
};
#endif