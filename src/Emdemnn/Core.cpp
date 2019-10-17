#include "Core.h"

std::shared_ptr<Core> Core::initialize()
{
  std::shared_ptr<Core> core = std::make_shared<Core>();
  return core;
}

void Core::start()
{

}

void Core::stop()
{

}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	return entity;
}
