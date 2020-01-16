#include "Resource.h"
#include "Core.h"

namespace Emdemnn
{
void Resource::onLoad()
{
  //std::cout << "Hello file has been loaded!" << std::endl;
}
	
std::shared_ptr<Core> Resource::getCore()
{
  return core.lock();
}
	
std::shared_ptr<Resources> Resource::getResources()
{
  return getCore()->getResources();
}
}
