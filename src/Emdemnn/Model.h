#include "Resource.h"
#include "Rend.h"

namespace Emdemnn
{
class MeshRenderer;	
	
class Model : public Resource
{
private:
  // Allows MeshRenderer class to access private variables from Mesh.
  friend class Emdemnn::MeshRenderer;
  
  std::shared_ptr<rend::Mesh> model;
  
public:
  void onLoad(const std::string& path);
};
}
