#include "Component.h"

namespace Emdemnn
{
class Camera : public Component
{
private:
  glm::mat4 view;
  glm::mat4 projection;
  
public:
  void onInit();

  glm::mat4 getView();
  glm::mat4 getProjection();
}
}
