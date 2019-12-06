#include <GL/glew.h>
#include <string>
#include <memory>
#include <vector>
#include <string>
#include <fstream>

#include "Rend.h"
#include "Excpetion

namespace Emdemnn
{
class Resources;
class Core;

class Resource
{
private:
  // Allows Resources class to access private variables from Resource.
  friend class Emdemnn::Resources;
  
  std::weak_ptr<Core> core;
  
public:
  void onLoad(std::string& path);
  
  // Getters.
  std::shared_ptr<Core> getCore();
  std::shared_ptr<Resources> getResources():
};
}