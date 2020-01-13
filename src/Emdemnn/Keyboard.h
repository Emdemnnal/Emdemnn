#include <memory>
#include <vector>

#include "Component.h"

namespace Emdemnn
{
class Keyboard : public Component
{
private:
  std::vector<int> keys;
  std::vector<int> pressedKeys;
  std::vector<int> releasedKeys;
  
public:
  bool isKey(int key);
  bool isKeyPressed(int key);
  bool iskeyReleased(int key);
}
}
