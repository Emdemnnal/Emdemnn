#include "Resource.h"
#include "Rend.h"

namespace Emdemnn
{
class MeshRenderer;		
	
class Material : public Resource
{
private:
  // Allows MeshRenderer class to access private variables from Mesh.
  friend class Emdemnn::MeshRenderer;
  
  std::shared_ptr<rend::Shader> shader;
  std::shared_ptr<rend::Texture> texture;
  
public:
  void onLoad(const std::string& path, const std::string& shaderPath);
};
}
