#include <memory>
#include <list>
#include <string>

namespace Emdemnn
{
class Resource;
class Core;

/**
 * Shows the structure oh how each resource can be added to resources.
 */
class Resources
{
private:
  friend class Emdemnn::Core; ///< Allows Core class to access private variables from Resources.
  std::list<std::shared_ptr<Resource>> resources; ///< List of resource types that resources can hold.
  
  std::weak_ptr<Core> core; ///< Reference to Core.
  std::weak_ptr<Resources> self; ///< Referebce to Self.

public:
  /// This is the function that is called to access Core.
  /**
   * On use, it allows access to the functionalities of the Core class.
   * \return The shared_ptr reference to core in Entity.
   */
  std::shared_ptr<Core> getCore();

  /// This is the function that is called to load a resource accepting one parameter.
  /**
   * On use, it auto creates an object of the added resource type and pushes it back to the list of resources.
   * It also sets the reference on that resource, such as references to core and resources.
   * It also calls the onLoad function on the added resource.
   * \return The resource type object.
   */
  template <typename T>
  std::shared_ptr<T> load(std::string path)
  {
    std::shared_ptr<T> t = std::make_shared<T>();
    // Set core pointer so it can go up.
    t->core = core;
	// Resource knows where it is.
    t->resources = self;
    // Calls onLoad function on loaded resources.
    t->onLoad(path);

    // Add to cache.
    resources.push_back(t);
	
	return t;
  }
  
  /// This is the function that is called to load a resource accepting two parameters.
  /**
   * On use, it auto creates an object of the added resource type and pushes it back to the list of resources.
   * It also sets the reference on that resource, such as references to core and resources.
   * It also calls the onLoad function on the added resource.
   * \return The resource type object.
   */
  template <typename T, typename A>
  std::shared_ptr<T> load(A path, A shaderPath)
  {
    std::shared_ptr<T> t = std::make_shared<T>();
    // Set core pointer so it can go up.
    t->core = core;
	// Resource knows where it is.
    t->resources = self;
    // Calls onLoad function on loaded resources.
    t->onLoad(path, shaderPath);

    // Add to cache.
    resources.push_back(t);
	
	return t;
  }
};
}