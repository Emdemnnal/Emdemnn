#include "Entity.h"
#include "Component.h"

namespace Emdemnn
{
void Entity::tick()
{
  for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
  {
    (*it)->onInit();
  }
}

void Entity::display()
{
  for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
  {
    (*it)->onDisplay(); 
  }
}

std::shared_ptr<Core> Entity::getCore()
{
  return core.lock();
}

std::shared_ptr<Transform> Entity::getTransform()
{
  return transform.lock();
}
}