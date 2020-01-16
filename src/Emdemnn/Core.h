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
class Keyboard;

/**
 * Represents the game engine where everything is kept.
 */
class Core
{
private:
  friend class Emdemnn::TriangleRenderer; ///< Allows renderer to access private variables from core.
  friend class Emdemnn::MeshRenderer; ///< Allows renderer to access private variables from core.
  friend class Emdemnn::Camera; ///< Allows camera class to access private variables from core.

  
  std::list<std::shared_ptr<Entity>> entities; ///< List of entities the engine holds.
  std::vector<std::shared_ptr<Camera>> cameras; ///< Vector of Camera objects.
  bool running; ///< Game Engine State.
  SDL_Window *window; ///< SDL window.
  SDL_GLContext glContext; ///< OpenGL Context.
  
  // OpenAL Device.
  //ALCdevice *device;
  // Sound Context.
  //ALCcontext *audioContext;
  
  std::weak_ptr<Core> self; ///< Reference to Self.
  std::shared_ptr<Context> context; ///< Setting up Context initialization.
  std::shared_ptr<Resources> resources; ///< Keeps a reference to the Resources.
  std::shared_ptr<Keyboard> keyboard; ///< Keeps a reference to the Keyboard.

public:
  /// Acts as the constructor for creating entities.
  /**
   * This initialize function auto creates an object of type core.
   * It also sets the initial references for various private variables, such as the resources and context.
   * This function is also responsible for creating a window output for the engine.
   * \return The core type object.
   */
  static std::shared_ptr<Core> initialize();
  
  /// The Core destructor.
  /**
   * This destructor handles cleanup, such as the cleanup required for SDL.
   * This includes the closing of the window and calling SDL_Quit();
   */
  ~Core();
  
  /// This is the function to call when a user wants to start running the game engine.
  /**
   * This engine start function is what loops through and calls the corresponding tick and display
     functions on the list of entities that the game engine contains.
   * It is also responsible for managing all keyboard input.
   * \return The core type object.
   */
  void start();
  
  /// This is the function that is called to stop the game engine from running.
  /**
   * This stop function sets the boolean to false as the engine only runs when it is true.
   */
  void stop();
  
  /// This is the function that is called to add an entity.
  /**
   * On use, it auto creates an object of type entity and pushes it back to the list of entities that core keeps.
   * It also sets various references on that entity such as a reference to itself as well as core.
   * This function also makes sure that each new entity created automatically has a transform component added.
   * \return The entity type object.
   */
  std::shared_ptr<Entity> addEntity();
  
  /// This is the function that is called to access Resources.
  /**
   * On use, it allows access to the functionalities of the Resources class.
   * \return The shared_ptr reference to resources.
   */
  std::shared_ptr<Resources> getResources();
  
  /// This is the function that is called to access the Context.
  /**
   * On use, it allows access to the functionalities of the Context class.
   * \return The shared_ptr reference to context.
   */
  std::shared_ptr<Context> getContext();
  
  /// This is the function that is called to access the current camera.
  /**
   * On use, it allows one to get the current active camera.
   * \return The shared_ptr reference to the first element of the cameras vector.
   */
  std::shared_ptr<Camera> getCurrentCamera();
  
   /// This is the function that is called to access the Keyboard.
  /**
   * On use, it allows one to get the functionalities of the Keyboard class.
   * \return The shared_ptr reference to keyboard.
   */
  std::shared_ptr<Keyboard> getKeyboard();
};
}
