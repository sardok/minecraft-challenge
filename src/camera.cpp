#include <camera.hpp>
#include <maths/matrix.hpp>

Camera::Camera()
{
    projection_matrix = make_projection_matrix(90);
    position = {0, 0, -3.5};
}

void Camera::update()
{
    position = entity->position;
    rotation = entity->rotation;

    view_matrix = make_view_matrix(*this);
    projection_view_matrix = projection_matrix * view_matrix;
}

void Camera::hook_entity(const Entity &entity)
{
    this->entity = &entity;
}

const Matrix4 &Camera::get_view_matrix() const noexcept
{
    return view_matrix;
}

const Matrix4 &Camera::get_projection_matrix() const noexcept
{
    return projection_matrix;
}

const Matrix4 &Camera::get_projection_view_matrix() const noexcept
{
    return projection_view_matrix;
}