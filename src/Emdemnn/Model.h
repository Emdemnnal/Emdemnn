#include "Resource.h"
#include "Rend.h"

namespace Emdemnn
{
class MeshRenderer;	

/**
 * Represents the derived class that inherited from the base class resource, with this one loading a model.
 */	
class Model : public Resource
{
private:
  friend class Emdemnn::MeshRenderer; ///< Allows MeshRenderer class to access private variables from Model.
  
  std::shared_ptr<rend::Mesh> model; ///< Keeps a reference to the Mesh in rend.
  
public:
  /// An onLoad() function that overrides the one from the base class Resource.
  /**
   * This onLoad() function is what is called when a new resource is added to resources.
   * This is the overriding function of the derived class.
   * It uses functionality from the rend wrapper of openGL to create a mesh, and then parses the file after
   * it has been read through a file reader and put into a string, again using rend.
   * \param path is the only argument, which takes a path to load a model.
   */
  void onLoad(const std::string& path);
};
}
