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
  for(size_t i = 0; i < pressedKeys.size(); i++)
  {
    if(pressedKeys.at(i) == key)
    {
      return true;
    }
  }

  return false;
}

bool Keyboard::isKeyReleased(int key)
{
  for(size_t i = 0; i < releasedKeys.size(); i++)
  {
    if(releasedKeys.at(i) == key)
    {
      return true;
    }
  }

  return false;
}
}
