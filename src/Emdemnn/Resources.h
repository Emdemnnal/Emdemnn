#include <memory>
#include <list>
#include <string>

namespace Emdemnn
{
class Resource;
class Core;

class Resources
{
private:
  // Allows Core class to access private variables from Resources.
  friend class Emdemnn::Core;
  std::list<std::shared_ptr<Resource>> resources;
  
  std::weak_ptr<Core> core;
  std::weak_ptr<Resources> self;

public:
  std::shared_ptr<Core> getCore();

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