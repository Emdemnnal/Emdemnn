#include "Resources.h"

namespace Emdemnn
{
std::shared_ptr<Core> Resources::getCore()
{
  return core.lock;
}
}