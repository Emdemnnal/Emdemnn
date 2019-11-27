#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <iostream>
#include <memory>

#include "Rend.h"

namespace Emdemnn
{

class Core;
class Entity;
class Transform;
class Resources;

class Component
{
private:
  // Allows Entity class to access variables from Component.
  friend class Emdemnn::Entity;
  
  std::weak_ptr<Entity> entity;
	
  virtual void onInit();
  virtual void onTick();
  virtual void onDisplay();

public:
  std::shared_ptr<Entity> getEntity();
  std::shared_ptr<Core> getCore();
  std::shared_ptr<Transform> getTransform();

  // Shortcut (getEntity()->getCore()->getResources())
  std::shared_ptr<Resources> getResources();
};
}
#endif
