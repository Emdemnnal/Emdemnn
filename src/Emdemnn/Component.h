#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <iostream>
#include <memory>

class Core;
class Entity;

class Component
{
private:
  friend class ::Entity;
  std::weak_ptr<Entity> entity;
	
  virtual void onInit();
  void onBegin();
  void onTick();
  virtual void onDisplay();

public:
  std::shared_ptr<Entity> getEntity();
  std::shared_ptr<Core> getCore();
};

#endif
