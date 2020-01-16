#include "Exception.h"

#include <memory>
#include <list>

namespace Emdemnn
{
class Component;
class Core;
class Transform;
class Resources;

/**
 * Shows the structure of each entity that can be added to core.
 */
class Entity
{
private:
  friend class Emdemnn::Core; ///< Allows Core class to access private variables from Entity.
  
  std::list<std::shared_ptr<Component>> components; ///< List of components that each entity holds.
  
  std::weak_ptr<Core> core; ///< Reference to Core.
  std::weak_ptr<Entity> self; ///< Reference to Self.
  std::weak_ptr<Transform> transform; ///< Reference to Transform. 
  
  /// Calls the onTick() function on each component.
  /**
   * This tick function iterates through each component on the entity's component list.
   * While iterating through this list of components, it calls the onTick() function on each component.
   */
  void tick();
  
  /// Calls the onDisplay() function on each component.
  /**
   * This display function iterates through each component on the entity's component list.
   * It also sets the initial references for various private variables.
   * While iterating through this list of components, it calls the onDisplay() function on each component.
   */
  void display();

public:
  /// This is the function that is called to access Core.
  /**
   * On use, it allows access to the functionalities of the Core class.
   * \return The shared_ptr reference to core.
   */
  std::shared_ptr<Core> getCore();
  
  /// This is the function that is called to access Transform.
  /**
   * On use, it allows access to the functionalities of the Transform class.
   * \return The shared_ptr reference to transform.
   */
  std::shared_ptr<Transform> getTransform();
  
  /// This is the function that is called to access Resources.
  /**
   * On use, it allows access to the functionalities of the Resources class.
   * \return The shared_ptr reference to resources in core.
   */
  std::shared_ptr<Resources> getResources();
  
  /// This is the function that is called to get a component.
  /**
   * On use, it iterates through the list of components that the entity holds.
   * When it find the component of the same type, it returns it.
   * \return The component type object.
   */
  template <typename T>
  std::shared_ptr<T> getComponent()
  {
    for (auto it = components.begin(); it != components.end(); ++it)
    {
      std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(*it);

      if(t)
      {
        return t;
      }
    }
     
    throw Exception("Doesn't Exist");
  }
  
  /// This is the function that is called to add a component.
  /**
   * On use, it auto creates an object of the added component type and pushes it back to the list of components each entity keeps.
   * It also sets the reference on that component, such as the reference to which entity its attached to.
   * It also calls the onInit function on the added component.
   * \return The component type object.
   */
  template <typename T>
  std::shared_ptr<T>addComponent()
  {
    std::shared_ptr<T> t = std::make_shared<T>();
  
    // Add it to the list of components on that entity.
    components.push_back(t);
    // Component knows what entity its attached to.
    t->entity = self; 
    // Call Initialize function on added component.
    t->onInit();
  
    return t;
  }
  
  /// This is the function that is called to add a component accepting one parameter.
  /**
   * On use, it auto creates an object of the added component type and pushes it back to the list of components each entity keeps.
   * It also sets the reference on that component, such as the reference to which entity its attached to.
   * It also calls the onInit() function on the added component, passing in the parameters. 
   * \return The component type object.
   */
  template <typename T, typename A>
  std::shared_ptr<T>addComponent(A a)
  {
    std::shared_ptr<T> t = std::make_shared<T>();

    // Add it to the list of components on that entity.
    components.push_back(t);
    // Component knows what entity its attached to.
    t->entity = self; 
    // Call Initialize function on added component.
    t->onInit(a);

    return t;
  }
  
  /// This is the function that is called to add a component accepting two parameters.
  /**
   * On use, it auto creates an object of the added component type and pushes it back to the list of components each entity keeps.
   * It also sets the reference on that component, such as the reference to which entity its attached to.
   * It also calls the onInit() function on the added component, passing in the parameters.
   * \return The component type object.
   */
  template <typename T, typename A, typename B>
  std::shared_ptr<T>addComponent(A a, B b)
  {   
    std::shared_ptr<T> t = std::make_shared<T>();
  
    // Add it to the list of components on that entity.
    components.push_back(t);
    // Component knows what entity its attached to.
    t->entity = self; 
    // Call Initialize function on added component.
    t->onInit(a, b);
  
    return t;
  }
  
  /// This is the function that is called to add a component accepting three parameters.
  /**
   * On use, it auto creates an object of the added component type and pushes it back to the list of components each entity keeps.
   * It also sets the reference on that component, such as the reference to which entity its attached to.
   * It also calls the onInit() function on the added component, passing in the parameters.
   * \return The component type object.
   */
  template <typename T, typename A, typename B, typename C>
  std::shared_ptr<T>addComponent(A a, B b, C c)
  {
    std::shared_ptr<T> t = std::make_shared<T>();
  
    // Add it to the list of components on that entity.
    components.push_back(t);
    // Component knows what entity its attached to.
    t->entity = self; 
    // Call Initialize function on added component.
    t->onInit(a, b, c);
  
    return t;
  }
};
}
