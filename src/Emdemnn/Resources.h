#include <memory>
#include <list>
#include <string>

class Resource;

class Resources
{
private:
  std::list<std::shared_ptr<Resource>>;

public:
  template <typename T>
  std::shared_ptr<T> load(std::string path)
  {
    
  }
  
  template <typename T>
  std::shared_ptr<T> create()
  {
    
  }
};
