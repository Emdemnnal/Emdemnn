#include <memory>
#include <vector>

#include "Component.h"

#include <SDL2/SDL.h>

#define EM_W SDLK_w
#define EM_S SDLK_s
#define EM_A SDLK_a
#define EM_D SDLK_d
#define EM_Q SDLK_q
#define EM_E SDLK_e

namespace Emdemnn
{

/**
 * Shows the structure of the Keyboard component that can be added to each entity.
 */
class Keyboard : public Component
{
private:
  friend class Emdemnn::Core; ///< Allows Core class to access private variables from Keyboard.

  std::vector<int> keys; ///< A vector of ints that stores the keys.
  std::vector<int> pressedKeys; ///< A vector of ints that stores the pressed keys.
  std::vector<int> releasedKeys; ///< A vector of ints that stores the released keys.
  
public:
  /// An isKey() function that checks for a matching key stored in the keys vector.
  /**
   * This isKey() function is what is called when certain SDL keys wants to be used.
   * This function checks the whole vector for the passed in value.
   * If it matches a value stored in the vector, it returns true, otherwise it returns false.
   * \param key is the only argument, which takes an integer value.
   * \return A boolean returning true or false.
   */
  bool isKey(int key);
  
  /// An isKey() function that checks for a matching key stored in the keys vector.
  /**
   * This isKey() function is what is called when certain SDL keys wants to be used.
   * This function checks the whole vector for the passed in value.
   * If it matches a value stored in the vector, it returns true, otherwise it returns false.
   * This uses function overloading as it takes in a different parameter.
   * \param key is the only argument, which takes a char value.
   * \return A boolean returning true or false.
   */
  bool isKey(char key);
  
  /// An isKeyPressed() function that checks for a matching key stored in the pressedKeys vector.
  /**
   * This isKey() function is what is called when certain SDL keys wants to be used.
   * This function checks the whole vector for the passed in value.
   * If it matches a value stored in the vector, it returns true, otherwise it returns false.
   * \param key is the only argument, which takes an integer value.
   * \return A boolean returning true or false.
   */
  bool isKeyPressed(int key);
  
  /// An isKeyReleased() function that checks for a matching key stored in the releasedKeys vector.
  /**
   * This isKey() function is what is called when certain SDL keys wants to be used.
   * This function checks the whole vector for the passed in value.
   * If it matches a value stored in the vector, it returns true, otherwise it returns false.
   * \param key is the only argument, which takes an integer value.
   * \return A boolean returning true or false.
   */
  bool isKeyReleased(int key);
};
}
