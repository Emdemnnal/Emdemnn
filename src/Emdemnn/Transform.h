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
   * This function is what is called on an entity to set its initial position in the world.
   * \param position is the only argument, which takes a vec3 to change the entity's Position.
   */
  void setPosition(glm::vec3 position);
  
  /// The setRotation() function.
  /**
   * This function is what is called on an entity to change its intial rotation in the world.
   * \param rotation is the only argument, which takes a vec3 to change the entity's Rotation.
   */
  void setRotation(glm::vec3 rotation);
  
  /// The setScale() function.
  /**
   * This function is what is called on an entity to change its initial scale or size in the world.
   * \param scale is the only argument, which takes a vec3 to change the entity's Scale.
   */
  void setScale(glm::vec3 scale);
  
  /// The translate() function.
  /**
   * This function is what is called on an entity to move or translate its position in the world by adding a new vector.
   * This creates a new identity matrix and multiplies on the xyz-axis of rotation to create a rotation matrix.
   * This rotation matrix is then used on the passed vec3 so that the entity moves based on its orientation.
   * \param amount is the only argument, which takes a vec3 to change the entity's Position.
   */
  void translate(glm::vec3 amount);
  
  /// The rotate() function.
  /**
   * This function is what is called on an entity to rotate its orientation in the world by adding a new vector.
   * This simply adds the passed in vec3 and adds it to the current vector that represents the enitity's orientation.
   * \param amount is the only argument, which takes a vec3 to change the entity's Rotation.
   */
  void rotate(glm::vec3 amount);
  
  /// The scale() function.
  /**
   * This function is what is called on an entity to change its scale or size in the world by adding a new vector.
   * This simply adds the passed in vec3 and adds it to the current vector that represents the enitity's scale.
   * \param amount is the only argument, which takes a vec3 to change the entity's Scale.
   */
  void scale(glm::vec3 amount);
  
  /// This is the function that is called to access the Entity's current Position.
  /**
   * This function is what called to return the position of an entity in the world.
   * \return The Position of the Entity.
   */
  glm::vec3 getPosition();
  
  /// This is the function that is called to return a model matrix.
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
