#include <memory>
#include <list>

class Component;
class Core;

class Entity
{
private:
  std::list<std::shared_ptr<Component>> components;
  std::weak_ptr<Core> core;
  
  void tick();
  void display();

public:
  template <typename T>
  std::shared_ptr<T>addComponent()
  {
    std::shared_ptr<T> t = std::make_shared<T>();
    components.push_back(t);

    return t;
  }

  template <typename T, typename A>
  std::shared_ptr<T>addComponent(A a)
  {
    return std::shared_ptr<T>();
  }

  template <typename T, typename A, typename B>
  std::shared_ptr<T>addComponent(A a, B b)
  {
    return std::shared_ptr<T>();
  }

  template <typename T, typename A, typename B, typename C>
  std::shared_ptr<T>addComponent(A a, B b, C c)
  {
    return std::shared_ptr<T>();
  }
};

