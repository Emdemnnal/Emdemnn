#include <memory>
#include <list>

#include <SDL2/SDL.h>

#include "Exception.h"
#include "Rend.h"

class Resources;

namespace Emdemnn
{
class Entity;

class Core
{
private:
  // List of entities the engine holds.
  std::list<std::shared_ptr<Entity>> entities;
  bool running;
  SDL_Window *window;
  //SDL_GLContext glContext;
  
  std::weak_ptr<Core> self;
  
  // Pointers for stuff.
  std::shared_ptr<Context> context;
  std::shared_ptr<Resources> resource;

public:
  static std::shared_ptr<Core> initialize();
  ~Core();

  void start();
  void stop();
  std::shared_ptr<Entity> addEntity();
};
}
