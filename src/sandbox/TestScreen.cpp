#include "TestScreen.h"

namespace Emdemnn
{

/*
void TestScreen::onInitialize()
{
  std::shared_ptr<MeshRenderer> mr = addComponent<MeshRenderer>();
  mr->setMesh(getResources()->load<Mesh>("models/room"));
}
*/

void TestScreen::onDisplay()
{
  std::cout << "Hello I am TestScreen Display!" << std::endl;
}
}
