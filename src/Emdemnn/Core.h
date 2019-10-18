#include <memory>
#include <list>

class Entity;

class Core
{
private:
  std::list<std::shared_ptr<Entity>> entities;
  bool running;

public:
  static std::shared_ptr<Core> initialize();
  void start();
  void stop();
  std::shared_ptr<Entity> addEntity();
};
