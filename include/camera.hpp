#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <entity.hpp>
#include <maths/glm.hpp>

class Camera : public Entity
{
  public:
    Camera();

    void update();
    void hook_entity(const Entity &entity);

    const Matrix4 &get_view_matrix() const noexcept;
    const Matrix4 &get_projection_matrix() const noexcept;
    const Matrix4 &get_projection_view_matrix() const noexcept;

  private:
    const Entity *entity;
    Matrix4 projection_matrix;
    Matrix4 view_matrix;
    Matrix4 projection_view_matrix;
};

#endif