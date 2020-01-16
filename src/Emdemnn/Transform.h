#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"

namespace Emdemnn
{
	
/**
 * The Transform class/component that manages the position, rotation and scale of each entity.
 */
class Transform : public Component
{
private:
  glm::vec3 Position; ///< A vec3 that represents an entity's position.
  glm::vec3 Rotation; ///< A vec3 that represents an entity's rotation.
  glm::vec3 Scale; ///< A vec3 that represents an entity's scale.
  
public:
  /// The onInit() function.
  /**
   * This onInit() function is what is called when a new component is added to an entity.
   * This is the overriding function of the derived class.
   * When this component is added to an entity, it makes sure that the scale is set to 1 and not 0
     so that it shows up in the world.
   */
  void onInit();
  
  /// The setPosition() function.
  /**
   * This function is what is called on an entity to change its position in the world.
   * \param position is the only argument, which takes a vec3 to change the entity's Position.
   */
  void setPosition(glm::vec3 position);
  
  /// The setRotation() function.
  /**
   * This function is what is called on an entity to change its rotation in the world.
   * \param rotation is the only argument, which takes a vec3 to change the entity's Rotation.
   */
  void setRotation(glm::vec3 rotation);
  
  /// The setScale() function.
  /**
   * This function is what is called on an entity to change its scale or size in the world.
   * \param scale is the only argument, which takes a vec3 to change the entity's Scale.
   */
  void setScale(glm::vec3 scale);
  
  // Relative to origin
  void translate(glm::vec3 amount);
  void rotate(glm::vec3 amount);
  void scale(glm::vec3 amount);
  
  // Relative to objects direction
  // void move(glm::vec3 amount);
  
  /// The getPosition() function.
  /**
   * This function is what called to return the position of an entity in the world.
   * \return The Position of the Entity.
   */
  glm::vec3 getPosition();
  
  /// The getModel() function which returns a model matrix.
  /**
   * This function is what is called to return a model matrix.
   * This function first creates an identity matrix.
   * That identity matrix is then Translated, Rotated, and Scaled using the entity's
     current Position, Rotation and Scale.
   * \return The Model Matrix.
   */
  glm::mat4 getModel();
};

}
