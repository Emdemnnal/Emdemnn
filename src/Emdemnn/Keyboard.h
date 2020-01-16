#include <memory>
#include <vector>

#include "Component.h"

namespace Emdemnn
{
class Keyboard : public Component
{
private:
  friend class Emdemnn::Core; ///< Allows Core class to access private variables from Keyboard.

  std::vector<int> keys;
  std::vector<int> pressedKeys;
  std::vector<int> releasedKeys;
  
public:
  bool isKey(int key);
  bool isKeyPressed(int key);
  bool iskeyReleased(int key);
};
}
