#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <iostream>
#include <memory>

namespace Emdemnn
{
class Core;
class Entity;
class Transform;
class Resources;

class Component
{
private:
  // Allows Entity class to access private variables from Component.
  friend class Emdemnn::Entity;
  
  std::weak_ptr<Entity> entity;
	
  virtual void onInit();
  virtual void onTick();
  virtual void onDisplay();

public:
  std::shared_ptr<Entity> getEntity();
  std::shared_ptr<Core> getCore();
  std::shared_ptr<Transform> getTransform();
  std::shared_ptr<Resources> getResources();
};
}
#endif
