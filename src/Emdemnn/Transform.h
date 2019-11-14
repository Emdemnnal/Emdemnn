#include <glm/glm.hpp>

#include "Component.h"

class Transform : public Component
{
private:
  glm::vec3 position;
  glm::vec3 rotation;
  glm::vec3 scale;
  
public:
  void setPosition(glm::vec3 position);
  glm::vec3 getPosition();
  glm::mat4 getModel();
};
