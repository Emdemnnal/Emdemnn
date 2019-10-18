#include "Component.h"
#include "Entity.h"

void Component::onInit()
{

}

void Component::onBegin()
{

}

void Component::onTick()
{

}

void Component::onDisplay()
{
  std::cout << "Hello I am Display!" << std::endl;
}

std::shared_ptr<Entity> Component::getEntity()
{
  return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
  return getEntity()->getCore();
}


