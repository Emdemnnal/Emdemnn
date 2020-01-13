#include "Keyboard.h"

namespace Emdemnn
{
bool Keyboard::isKey(int key)
{
  for(size_t i = 0; i < keys.size(); i++)
  {
    if(keys.at(i) == key)
    {
      return true;
    }
  }

  return false;
}

bool Keyboard::isKeyPressed(int key)
{
  
}

bool Keyboard::isKeyReleased(int key)
{
  
}
}
