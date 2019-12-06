#include <GL/glew.h>
#include <string>
#include <memory>
#include <vector>
#include <string>

#include "Rend.h"

namespace Emdemnn
{
class Resources;

class Resource
{
private:
  // Allows Resources class to access private variables from Resource.
  friend class Resources;
  
  std::weak_ptr<Resources> resources;
  std::weak_ptr<Core> core;
  
  std::string path;
  
public:
  void onLoad(std::string& path);
  
  std::shared_ptr<Resources> getResources():
};
}