#include <camera.hpp>
#include <renderer/chunk_renderer.hpp>
#include <world/block/block_database.hpp>
#include <world/chunk/chunk_mesh.hpp>

void ChunkRenderer::add(const ChunkMesh &mesh)
{
    chunks.push_back(&mesh);
}

void ChunkRenderer::render(const Camera &camera)
{
    shader.use_program();

    BlockDatabase::get().texture_atlas.bind_texture();

    shader.load_projection_view_matrix(camera.get_projection_view_matrix());

    for (const ChunkMesh *mesh : chunks)
    {
        const ChunkMesh &m = *mesh;

        m.get_model().bind_vao();
        glDrawElements(
            GL_TRIANGLES,
            m.get_model().get_indices_count(),
            GL_UNSIGNED_INT,
            nullptr
        );
    }

    chunks.clear();
}