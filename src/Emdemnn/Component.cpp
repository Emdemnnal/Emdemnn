#include "Component.h"
#include "Entity.h"

void Component::onInit()
{
  std::cout << "Hello I am Init!" << std::endl;
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

std::shared_ptr<Transform> Component::getTransform()
{
  
}
