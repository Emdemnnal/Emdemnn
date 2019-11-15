#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Component.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

namespace Emdemnn
{
class MeshRenderer : public Component
{
private:
  SDL_Window *window;
  GLuint programId;
  GLuint vaoId;
  bool quit;
  
  void onDisplay();
 
public:
  ~MeshRenderer();
  void onInit();
  //void setMesh(std::weak_ptr<Mesh> mesh);
  //std::shared_ptr<Mesh> getMesh();
  //std::shared_ptr<Material> getMaterial();
  
};
}