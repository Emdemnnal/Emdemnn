#include <glm/glm.hpp>

#include "Component.h"

namespace Emdemnn
{
class Transform : public Component
{
private:
  glm::vec3 Position;
  glm::vec3 Rotation;
  glm::vec3 Scale;
  
public:
  void setPosition(glm::vec3 position);
  void setRotation(glm::vec3 rotation);
  void setScale(glm::vec3 scale);
  
  void translate(glm::vec3 amount);
  void rotate(glm::vec3 amount);
  void scale(glm::vec3 amount);
  
  glm::vec3 getPosition();
  glm::mat4 getModel();
};
}