#include <memory>

#include "Component.h"

namespace Emdemnn
{
class Model;
class Material;	

/**
 * Shows the structure of the MeshRenderer component that can be added to each entity.
 */	
class MeshRenderer : public Component
{
private:
  std::shared_ptr<Model> mesh; ///< Reference to engine's Mesh Class.
  std::shared_ptr<Material> material; ///< Reference to engine's Material Class.
  
  /// An onDisplay() function that overrides the one from the base class Component.
  /**
   * This onDisplay() function is what is called when a new component is added to an entity.
   * This is the overriding function of the derived class.
   * This function sets the texture, the model, view and projection matrices inside the shader, and the mesh.
   * It then calls the render function. 
   * This component has access to rend functionalities due to its references to the Mesh and Material classes.
   */
  void onDisplay();
 
public:

  /// The setMesh() function.
  /**
   * This function is what is called on this component attached to an entity to pass it a resource.
   * \param mesh is the only argument, which takes a shared_ptr of a Model type resource and assigns it to mesh.
   */
  void setMesh(std::shared_ptr<Model> mesh);
  
  /// The setMaterial() function.
  /**
   * This function is what is called on this component attached to an entity to pass it a resource.
   * \param material is the only argument, which takes a shared_ptr of a Material type resource and assigns it to material.
   */
  void setMaterial(std::shared_ptr<Material> material);
  
  /// This is the function that is called to access Mesh.
  /**
   * On use, it allows access to the functionalities of the Mesh class.
   * \return The shared_ptr reference to mesh.
   */
  std::shared_ptr<Model> getMesh();
  
  /// This is the function that is called to access Material.
  /**
   * On use, it allows access to the functionalities of the Material class.
   * \return The shared_ptr reference to material.
   */
  std::shared_ptr<Material> getMaterial();
};
}
