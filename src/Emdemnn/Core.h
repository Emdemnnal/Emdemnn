#include <memory>
#include <list>

#include <SDL2/SDL.h>

#include <exception>

class Entity;

class Core
{
private:
  std::list<std::shared_ptr<Entity>> entities;
  bool running;
  SDL_Window *window;

public:
  static std::shared_ptr<Core> initialize();
  void start();
  void stop();
  std::shared_ptr<Entity> addEntity();
};
