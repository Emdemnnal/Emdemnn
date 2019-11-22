#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <memory>

#include "Component.h"
#include "Rend.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class Mesh;
class Material;

namespace Emdemnn
{
class MeshRenderer : public Component
{
private:
  GLuint programId;
  GLuint vaoId;
  bool quit;
  
  //std::weak_ptr<Mesh> mesh;
  //std::shared_ptr<Material> material;
  
  void onDisplay();
 
public:
  void onInit();
  //void setMesh(std::weak_ptr<Mesh> mesh);
  //std::shared_ptr<Mesh> getMesh();
  //std::shared_ptr<Material> getMaterial();
  
};
}
