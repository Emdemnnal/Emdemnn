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
class MeshRenderer;
class Camera;

class Core
{
private:
  // Allows renderer to access private variables from core.
  friend class Emdemnn::TriangleRenderer;
   // Allows renderer to access private variables from core.
  friend class Emdemnn::MeshRenderer;
  // Allows camera class to access private variables from core.
  friend class Emdemnn::Camera;

  // List of entities the engine holds.
  std::list<std::shared_ptr<Entity>> entities;
  // Vector of Camera objects.
  std::vector<std::shared_ptr<Camera>> cameras;
  // Game Engine State.
  bool running;
  // SDL window.
  SDL_Window *window;
  // OpenGL Context.
  SDL_GLContext glContext;
  // OpenAL Device.
  //ALCdevice *device;
  // Sound Context.
  //ALCcontext *audioContext;
  
  // Reference to self
  std::weak_ptr<Core> self;
  
  // Setting up Context initialization.
  std::shared_ptr<Context> context;

  // Keeps a reference to the resources.
  std::shared_ptr<Resources> resources;

public:
  static std::shared_ptr<Core> initialize();
  ~Core();

  void start();
  void stop();
  std::shared_ptr<Entity> addEntity();
  
  std::shared_ptr<Resources> getResources();
  std::shared_ptr<Context> getContext();
  std::shared_ptr<Camera> getCurrentCamera();
};
}
