#include <memory>
#include <list>
#include <string>

class Resource;

class Resources
{
private:
  std::list<std::shared_ptr<Resource>> resources;

public:
  template <typename T>
  std::shared_ptr<T> load(std::string path)
  {
    std::shared_ptr<T> t = std::make_shared<T>();
	
	resources.push_back(t);
  }
  
  template <typename T>
  std::shared_ptr<T> create()
  {
    
  }
};
