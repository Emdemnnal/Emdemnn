#include "Resource.h"
#include "Rend.h"

namespace Emdemnn
{
class Material : public Resource
{
private:
  std::shared_ptr<Shader> shader;
  std::shared_ptr<Texture> texture;
  
public:
  void onLoad(const std::string& path);
  
  std::shared_ptr getCore();
};
}
