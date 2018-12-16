#include <vector>
#include <SFML/Graphics.hpp>
#include <camera.hpp>
#include <renderer/cube_renderer.hpp>

CubeRenderer::CubeRenderer()
    : atlas_test("DefaultPack")
{
    texture.load_from_file("test");

    std::vector<GLfloat> vertex_coords
    {
        // Back
        1, 0, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0,

        // Front
        0, 0, 1,
        1, 0, 1,
        1, 1, 1,
        0, 1, 1,

        // Right
        1, 0, 1,
        1, 0, 0,
        1, 1, 0,
        1, 1, 1,

        // Left
        0, 0, 0,
        0, 0, 1,
        0, 1, 1,
        0, 1, 0,

        // Top
        0, 1, 1,
        1, 1, 1,
        1, 1, 0,
        0, 1, 0,

        // Bottom
        0, 0, 0,
        1, 0, 0,
        1, 0, 1,
        0, 0, 1,
    };

    auto top = atlas_test.get_texture({0, 0});
    auto side = atlas_test.get_texture({1, 0});
    auto bottom = atlas_test.get_texture({2, 0});

    std::vector<GLfloat> tex_coords;
    tex_coords.insert(tex_coords.end(), side.begin(), side.end());
    tex_coords.insert(tex_coords.end(), side.begin(), side.end());
    tex_coords.insert(tex_coords.end(), side.begin(), side.end());
    tex_coords.insert(tex_coords.end(), side.begin(), side.end());
    tex_coords.insert(tex_coords.end(), top.begin(), top.end());
    tex_coords.insert(tex_coords.end(), bottom.begin(), bottom.end());

    std::vector<GLuint> indices
    {
        0, 1, 2,
        2, 3, 0,

        4, 5, 6,
        6, 7, 4,

        8, 9, 10,
        10, 11, 18,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20,
    };

    cube_model.add_data({vertex_coords, tex_coords, indices});
}

void CubeRenderer::add(const Vector3 &pos)
{
    quads.push_back(pos);
}

void CubeRenderer::render(const Camera &camera)
{
    shader.use_program();
    cube_model.bind_vao();
    atlas_test.bind_texture();

    shader.load_projection_view_matrix(camera.get_projection_view_matrix());

    for (auto &quad: quads)
    {
        shader.load_model_matrix(make_model_matrix({quad, {0, 0, 0}}));
        glDrawElements(
            GL_TRIANGLES,
            cube_model.get_indices_count(),
            GL_UNSIGNED_INT,
            nullptr);
    }

    quads.clear();
}