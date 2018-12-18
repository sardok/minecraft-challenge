#ifndef MESH_HPP
#define MESH_HPP
#include <vector>
#include <glad/glad.h>

struct Mesh
{
    std::vector<GLfloat>  vertex_positions;
    std::vector<GLfloat> texture_coords;
    std::vector<GLuint> indices;
};
#endif