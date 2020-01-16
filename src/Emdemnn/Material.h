#include "Resource.h"
#include "Rend.h"

namespace Emdemnn
{
class MeshRenderer;		

/**
 * Represents the derived class that inherited from the base class resource, with this one loading a shader and texture.
 */	
class Material : public Resource
{
private:
  friend class Emdemnn::MeshRenderer; ///< Allows MeshRenderer class to access private variables from Material.
  
  std::shared_ptr<rend::Shader> shader; ///< Keeps a reference to the Shader in rend.
  std::shared_ptr<rend::Texture> texture; ///< Keeps a reference to the Texture in rend.
  
public:
  /// An onLoad() function that overrides the one from the base class Resource.
  /**
   * This onLoad() function is what is called when a new resource is added to resources.
   * This is the overriding function of the derived class.
   * It uses functionality from the rend wrapper of openGL to create a shader, and then parses the second argument
     after it has been read through a file reader and put into a string, again using rend.
   * It then uses rend to create a texture, in which the first argument is converted into a c-string and used.
   * \param path is the first argument, which takes a path to load a texture.
   * \param shaderPath is the second argument, which takes a path to load a shader file.
   */
  void onLoad(const std::string& path, const std::string& shaderPath);
};
}
