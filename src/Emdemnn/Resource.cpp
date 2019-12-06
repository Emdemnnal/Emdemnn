#include "Resource.h"

namespace Emdemnn
{	
std::shared_ptr<Core> Material::getCore()
{
  return core.lock;
}
	
std::shared_ptr<Resources> Material::getResources()
{
  return getCore->getResources();
}
}
