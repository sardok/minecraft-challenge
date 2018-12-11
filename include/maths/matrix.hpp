#ifndef MATHS_MATRIX_HPP
#define MATHS_MATRIX_HPP
#include "glm.hpp"

class Camera;
class Entity;

Matrix4 make_model_matrix(const Entity &entity);
Matrix4 make_view_matrix(const Camera &camera);
Matrix4 make_projection_matrix(float fov);
#endif