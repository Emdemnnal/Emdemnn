#include <Emdemnn/Emdemnn.h>
//#include <Emdemnn/Emdemnn_Core.h>

#include <iostream>
#include <memory>

int main()
{
  // Initialize our engine.
  std::shared_ptr<Core> core = Core::initialize();
  std::cout << "Emdemnn Engine" << std::endl;
  
  // Create a single in-game object.
  std::shared_ptr<Entity> entity = core->addEntity();

  // Add a very simple component to it.
  //std::weak_ptr<TestScreen> testScreen = entity->addComponent<TestScreen>();

  // Start the engine's main loop.
  core->start();

/*
  std::shared_ptr<Foo> f = std::make_shared<TestFoo>();

  Foo* f = new TestFoo();
*/

  return 0;
}
