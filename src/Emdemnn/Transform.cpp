#include "Transform.h"

namespace Emdemnn
{

void Transform::onInit()
{
  // Initializes the scale to 1 so it doesn't zero-initialize.
  Scale = glm::vec3(1, 1, 1);
}

void Transform::setPosition(glm::vec3 position)
{
  Position = position;
}

void Transform::setRotation(glm::vec3 rotation)
{
  Rotation = rotation;
}

void Transform::setScale(glm::vec3 scale)
{
  Scale = scale;
}

void Transform::translate(glm::vec3 amount)
{
  glm::mat4 m = glm::mat4(1.0f);

  m = glm::rotate(m, Rotation.x, glm::vec3(1, 0, 0));
  m = glm::rotate(m, Rotation.y, glm::vec3(0, 1, 0));
  m = glm::rotate(m, Rotation.z, glm::vec3(0, 0, 1));

  glm::vec3 diff = glm::vec3(m * glm::vec4(amount, 1));
  Position += diff;
}

void Transform::rotate(glm::vec3 amount)
{
  Rotation += amount;
}

void Transform::scale(glm::vec3 amount)
{
  Scale += amount;
}

glm::vec3 Transform::getPosition()
{
  return Position;
}

glm::mat4 Transform::getModel()
{
  // Translate, rotate then scale.
  // m = s * r * t.
  
  // Initialize Identity Matrix.
  glm::mat4 m = glm::mat4(1.0f);
  
  m = glm::translate(m, Position);
  
  // Multiplies the matrix on the x-axis of rotation.
  m = glm::rotate(m, Rotation.x, glm::vec3(1, 0, 0));
  // Multiplies the matrix on the y-axis of rotation.
  m = glm::rotate(m, Rotation.y, glm::vec3(0, 1, 0));
  // Multiplies the matrix on the z-axis of rotation.
  m = glm::rotate(m, Rotation.z, glm::vec3(0, 0, 1));
  
  m = glm::scale(m, Scale);
  
  return m;
}
}
