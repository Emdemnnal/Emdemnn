#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <iostream>
#include <memory>

namespace Emdemnn
{
class Core;
class Entity;
class Transform;
class Resources;
class Keyboard;

/**
 * Shows the basic structure that each component will inherit from.
 */
class Component
{
private:
  friend class Emdemnn::Entity; ///< Allows Entity class to access private variables from Component.
  
  std::weak_ptr<Entity> entity; ///< Reference to Entity containing this component.
	
  /// A virtual onInit() function.
  /**
   * This onInit() function is what is called when a new component is added to an entity.
   * It is a virtual function, so that it calls the onInit() function instead on classes that inherit from component.
   * As a base class, this function does nothing.
   */
  virtual void onInit();
  
  /// A virtual onTick() function.
  /**
   * This onTick() function is called when entity iterates through each component calling this function.
   * It is a virtual function, so that it calls the onTick() function instead on classes that inherit from component.
   * As a base class, this function does nothing.
   */
  virtual void onTick();
  
  /// A virtual onDisplay() function.
  /**
   * This onDisplay() function is called when entity iterates through each component calling this function.
   * It is a virtual function, so that it calls the onDisplay() function instead on classes that inherit from component.
   * As a base class, this function does nothing.
   */
  virtual void onDisplay();

public:
  /// This is the function that is called to access the containing Entity.
  /**
   * On use, it allows access to the functionalities of the Entity class.
   * \return The shared_ptr reference to entity.
   */
  std::shared_ptr<Entity> getEntity();
  
  /// This is the function that is called to access Core.
  /**
   * On use, it allows access to the functionalities of the Core class.
   * \return The shared_ptr reference to core in Entity.
   */
  std::shared_ptr<Core> getCore();
  
  /// This is the function that is called to access Transform.
  /**
   * On use, it allows access to the functionalities of the Transform class.
   * \return The shared_ptr reference to transform in Entity.
   */
  std::shared_ptr<Transform> getTransform();
  
  /// This is the function that is called to access Resources.
  /**
   * On use, it allows access to the functionalities of the Resources class.
   * \return The shared_ptr reference to resources in core.
   */
  std::shared_ptr<Resources> getResources();
  
  /// This is the function that is called to access Keyboard.
  /**
   * On use, it allows access to the functionalities of the Keyboard class.
   * \return The shared_ptr reference to keyboard in core.
   */
  std::shared_ptr<Keyboard> getKeyboard();
};
}
#endif
