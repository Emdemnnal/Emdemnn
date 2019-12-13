#include "Resource.h"
#include "Core.h"

namespace Emdemnn
{	
std::shared_ptr<Core> Resource::getCore()
{
  return core.lock();
}
	
std::shared_ptr<Resources> Resource::getResources()
{
  return getCore()->getResources();
}
}
