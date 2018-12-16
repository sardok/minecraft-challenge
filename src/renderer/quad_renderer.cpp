#include <iostream>
#include <renderer/quad_renderer.hpp>
#include <camera.hpp>
#include <maths/matrix.hpp>
#include <mesh.hpp>

QuadRenderer::QuadRenderer()
{
    texture.load_from_file("test");

    auto mesh = Mesh{

        .vertex_positions = {
            -0.5, 0.5, 0,
            0.5, 0.5, 0,
            0.5, -0.5, 0,
            -0.5, -0.5, 0},
        .texture_coords = {
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
        },
        .indices = {
            0,
            1,
            2,
            2,
            3,
            0,
        }};

    quad_model.add_data(mesh);
}

void QuadRenderer::add(const Vector3 &position)
{
    quads.push_back(position);
}

void QuadRenderer::render_quads(const Camera &camera)
{
    shader.use_program();
    quad_model.bind_vao();
    texture.bind_texture();

    shader.load_projection_view_matrix(camera.get_projection_view_matrix());

    for (auto &quad : quads)
    {
        auto model_matrix = make_model_matrix({quad, {0, 0, 0}});
        shader.load_model_matrix(model_matrix);

        glDrawElements(
            GL_TRIANGLES,
            quad_model.get_indices_count(),
            GL_UNSIGNED_INT,
            nullptr);
    }

    quads.clear();
}