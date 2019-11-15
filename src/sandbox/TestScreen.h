#include <iostream>
#include <memory>

#include "../Emdemnn/Component.h"

namespace Emdemnn
{
class TestScreen : public Component
{
public:
  void onDisplay();
};
}