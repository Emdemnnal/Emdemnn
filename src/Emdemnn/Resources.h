#include <memory>
#include <list>
#include <string>

class Resource;
class Core;

class Resources
{
private:
  std::list<std::shared_ptr<Resource>> resources;
  std::weak_ptr<Resources> self;
  std::weak_ptr<Core> core;

public:
  template <typename T>
  std::shared_ptr<T> load(std::string path)
  {
    // loop through resources
      // if resource.path == path
        return resource

    std::shared_ptr<T> t = std::make_shared<T>();
    // Set core pointer so it can go up
    //t->core = core;
    //t->resources = self;

    t->load(path);

    // Add to cache
    resources.push_back(t);
  }
  
  template <typename T>
  std::shared_ptr<T> create()
  {

  }
};
