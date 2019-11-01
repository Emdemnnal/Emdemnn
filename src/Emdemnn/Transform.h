#include <glm/glm.hpp>

#include "Component.h"

class Transform : public Component
{
private:
  vec3 position;
  vec3 rotation;
  vec3 scale;
  
public:
  void setPosition(vec3 position);
  vec3 getPosition();
  mat4 getModel();
}
