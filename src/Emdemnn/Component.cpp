#include "Component.h"
#include "Entity.h"
#include "Core.h"

namespace Emdemnn
{
void Component::onInit()
{
  std::cout << "Hello I am Init!" << std::endl;
}

void Component::onTick()
{
  std::cout << "Hello I am Ticking!" << std::endl;
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
  return getEntity()->getTransform();
}

std::shared_ptr<Resources> Component::getResources()
{
  return getEntity()->getCore()->getResources();
}
}