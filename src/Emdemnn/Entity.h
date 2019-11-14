#include <memory>
#include <list>
#include "Exception.h"

class Component;
class Core;
class Transform;

class Entity
{
private:
  // Allows Entity class to access variable from Core.
  friend class ::Core;
  // List of components that entity holds.
  std::list<std::shared_ptr<Component>> components;
  std::weak_ptr<Core> core;
  std::weak_ptr<Entity> self;
  std::weak_ptr<Transform> transform;
  
  void tick();
  void display();

public:
  std::shared_ptr<Core> getCore();
  
  template <typename T>
  std::shared_ptr<T> getComponent()
  {
	  for (auto it = components.begin(); it != components.end(); ++it)
	  {
		  std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(*it);
		  return t;
	  }
	   
	  throw rend::Exception("Doesn't Exist");
  }
  
  std::shared_ptr<Transform> getTransform();

  template <typename T>
  std::shared_ptr<T>addComponent()
  {
    std::shared_ptr<T> t = std::make_shared<T>();
    components.push_back(t);
	
	// Component knows what entity its attached to.
    t->entity = self; 
	
    return t;
  }

  template <typename T, typename A>
  std::shared_ptr<T>addComponent(A a)
  {
    std::shared_ptr<T> t = std::make_shared<T>(a);
    components.push_back(t);
	
	// Component knows what entity its attached to.
	t->entity = self;

    return t;
  }

  template <typename T, typename A, typename B>
  std::shared_ptr<T>addComponent(A a, B b)
  {   
    std::shared_ptr<T> t = std::make_shared<T>(a, b);
    components.push_back(t);
	
	// Component knows what entity its attached to.
	t->entity = self;

    return t;
  }

  template <typename T, typename A, typename B, typename C>
  std::shared_ptr<T>addComponent(A a, B b, C c)
  {
    
    std::shared_ptr<T> t = std::make_shared<T>(a, b, c);
    components.push_back(t);
	
	// Component knows what entity its attached to.
	t->entity = self;

    return t;
    //return std::shared_ptr<T>();
  }
};

