#ifndef _RESOURCE_H
#define _RESOURCE_H

#include <GL/glew.h>
#include <string>
#include <memory>
#include <vector>
#include <string>
#include <fstream>

#include "Rend.h"
#include "Exception.h"

namespace Emdemnn
{
class Resources;
class Core;

/**
 * Shows the basic structure that each resource will inherit from.
 */
class Resource
{
private:
  friend class Emdemnn::Resources; ///< Allows Resources class to access private variables from Resource.
  
  std::weak_ptr<Core> core; ///< Reference to Core.
  std::weak_ptr<Resources> resources; ///< Reference to Resources.
  
public:
  /// A virtual onLoad() function.
  /**
   * This onInit() function is what is called when a new resource is added to resources.
   * It is a virtual function, so that it calls the onLoad() function instead on classes that inherit from resource.
   * As a base class, this function does nothing.
   */
  virtual void onLoad();
  
  /// This is the function that is called to access Core.
  /**
   * On use, it allows access to the functionalities of the Core class.
   * \return The shared_ptr reference to core.
   */
  std::shared_ptr<Core> getCore();
  
  /// This is the function that is called to access Resources.
  /**
   * On use, it allows access to the functionalities of the Resources class.
   * \return The shared_ptr reference to resources.
   */
  std::shared_ptr<Resources> getResources();
};
}
#endif
