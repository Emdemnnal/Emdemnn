#include "Core.h"
#include "Entity.h"
#include "Component.h"

std::shared_ptr<Core> Core::initialize()
{
  std::shared_ptr<Core> core = std::make_shared<Core>();

  return core;
}

void Core::start()
{
  running = true;
  while(running != false)
  {
    for (std::list<std::shared_ptr<Entity>>::iterator it = entity.begin(); it != entity.end(); ++it)
    {
      (*it) -> display(); 
    }
  }
}

void Core::stop()
{
    running = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
  std::shared_ptr<Entity> entity = std::make_shared<Entity>();
  this->entity.push_back(entity);

  return entity;
}
