
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Component.h"
#include "Rend.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

namespace Emdemnn
{
class TriangleRenderer : public Component
{
private:
  std::shared_ptr<Shader> shader;
  std::shared_ptr<Buffer> buffer;
  
  void onDisplay();
 
public:
  void onInit();
};
}
