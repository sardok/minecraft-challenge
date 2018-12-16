#include <iostream>
#include <world/world_constants.hpp>
#include <world/chunk/chunk_mesh.hpp>

ChunkMesh::ChunkMesh()
{
}

void ChunkMesh::add_face(
    const std::vector<GLfloat> &block_face,
    const std::vector<GLfloat> &texture_coords,
    const sf::Vector3i &chunk_position,
    const sf::Vector3i &block_position)
{
    auto &verticies = mesh.vertex_positions;
    auto &tex_coords = mesh.texture_coords;
    auto &indices = mesh.indices;

    tex_coords.insert(tex_coords.end(), texture_coords.begin(), texture_coords.end());

    ///Vertex: The current vertex in the "blockFace" vector, 4 vertex in total hence "< 4"
    ///Index: X, Y, Z
    for (int i = 0, index = 0; i < 4; ++i)
    { 
        verticies.push_back(block_face[index++] + chunk_position.x * CHUNK_SIZE + block_position.x);
        verticies.push_back(block_face[index++] + chunk_position.y * CHUNK_SIZE + block_position.y);
        verticies.push_back(block_face[index++] + chunk_position.z * CHUNK_SIZE + block_position.z);
    }

    indices.insert(indices.end(),
                   {index_index,
                    index_index + 1,
                    index_index + 2,

                    index_index + 2,
                    index_index + 3,
                    index_index});

    index_index += 4;
}

void ChunkMesh::buffer_mesh()
{
    std::cout   << "Buffered"
                << "\nVertex:   " << mesh.vertex_positions.size()
                << "\nTextures: " << mesh.texture_coords.size()
                << "\nIndices:  " << mesh.indices.size() << "\n";

    model.add_data(mesh);

    mesh.vertex_positions.clear();
    mesh.texture_coords.clear();
    mesh.indices.clear();

    mesh.vertex_positions.shrink_to_fit();
    mesh.texture_coords.shrink_to_fit();
    mesh.indices.shrink_to_fit();

    index_index = 0;
}

const Model &ChunkMesh::get_model() const
{
    return model;
}