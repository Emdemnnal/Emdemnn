#include <memory>
#include <list>

#include <SDL2/SDL.h>

#include "Exception.h"
#include "Rend.h"

namespace Emdemnn
{
class Entity;
class Resources;
class TriangleRenderer;

class Core
{
private:
  friend class TriangleRenderer;

  // List of entities the engine holds.
  std::list<std::shared_ptr<Entity>> entities;
  bool running;
  SDL_Window *window;
  SDL_GLContext glContext;
  
  std::weak_ptr<Core> self;
  
  // Pointers for stuff.
  std::shared_ptr<Context> context;

  // TODO: Make a shared_ptr
  std::weak_ptr<Resources> resources;

public:
  static std::shared_ptr<Core> initialize();
  ~Core();

  void start();
  void stop();
  std::shared_ptr<Entity> addEntity();
  std::shared_ptr<Resources> getResources();
};
}
