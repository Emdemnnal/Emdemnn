#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"

namespace Emdemnn
{
class Camera : public Component
{
private:
  
public:
  void onInit();

  glm::mat4 getView();
  glm::mat4 getProjection();
};
}
