#include "Resource.h"
#include "Rend.h"

namespace Emdemnn
{
class Mesh : public Resource
{
private:
  std::shared_ptr<Mesh> mesh;
  
public:
  void onLoad(const std::string& path);
};
}