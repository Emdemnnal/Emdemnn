#include <memory>

#include "Component.h"

namespace Emdemnn
{
class Model;
class Material;	
	
class MeshRenderer : public Component
{
private:
  // Reference to engine's Mesh Class.
  std::shared_ptr<Model> mesh;
  // Reference to engine's Material Class.
  std::shared_ptr<Material> material;
  
  void onDisplay();
 
public:
  void onInit();
  
  void setMesh(std::shared_ptr<Model> mesh);
  void setMaterial(std::shared_ptr<Material> material);
  
  std::shared_ptr<Model> getMesh();
  std::shared_ptr<Material> getMaterial();
};
}
