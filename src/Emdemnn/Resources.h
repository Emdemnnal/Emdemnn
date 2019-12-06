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
  std::list<std::shared_ptr<Resource>> resources;
  
  std::weak_ptr<Core> core;
  std::weak_ptr<Resources> self;

public:
  template <typename T>
  std::shared_ptr<T> load(std::string path)
  {
    // loop through resources
      // if resource.path == path
	  // return resource
	/*
	for(std::list<std::shared_ptr<Resource>::iterator it = resources.begin(); it != resources.end(); it++)
	{
	  if(resource.path == path)
	  {
        return resource;
	  }
	} 
    */
    std::shared_ptr<T> t = std::make_shared<T>();
    // Set core pointer so it can go up.
    t->core = core;
	// Resource knows where it is.
    t->resources = self;
    // Calls onLoad function on loaded resources.
    t->onLoad(path);

    // Add to cache.
    resources.push_back(t);
  }
  
  /*
  template <typename T>
  std::shared_ptr<T> create()
  {

  }*/
};
}