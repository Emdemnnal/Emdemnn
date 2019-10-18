#include "Entity.h"
#include "Component.h"

void Entity::tick()
{

}

void Entity::display()
{
  for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); ++it)
  {
    (*it) -> onDisplay(); 
  }
}

std::shared_ptr<Core> Entity::getCore()
{
  return core.lock();
}
