#include <memory>
#include <list>

#include <SDL2/SDL.h>

#include <exception>

class Entity;

class Core
{
private:
  // List of entities the engine holds.
  std::list<std::shared_ptr<Entity>> entities;
  bool running;
  SDL_Window *window;
  std::weak_ptr<Core> self;

public:
  static std::shared_ptr<Core> initialize();
  void start();
  void stop();
  std::shared_ptr<Entity> addEntity();
};
