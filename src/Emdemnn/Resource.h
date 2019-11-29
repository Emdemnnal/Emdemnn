#include <GL/glew.h>
#include <string>
#include <memory>
#include <vector>
#include <string>

#include "Rend.h"

class Resources;

class Resource
{
private:
  // Allows Resources class to access private variables from Resource.
  friend class Resources;
  std::weak_ptr<Resources> resources;
  
  std::string path;
  
public:
  std::shared_ptr<Resources> getResources():
};
