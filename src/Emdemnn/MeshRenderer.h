#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <memory>

#include "Component.h"
//#include "Rend.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class Mesh;
class Material;

namespace Emdemnn
{
class MeshRenderer : public Component
{
private:
  // Reference to engine's Mesh Class.
  std::shared_ptr<Mesh> mesh;
  // Reference to engine's Material Class.
  std::shared_ptr<Material> material;
  
  void onDisplay();
 
public:
  void onInit();
  
  void setMesh(std::shared_ptr<Mesh> mesh);
  void setMaterial(std::shared_ptr<Material> material);
  
  std::shared_ptr<Mesh> getMesh();
  std::shared_ptr<Material> getMaterial();
};
}
