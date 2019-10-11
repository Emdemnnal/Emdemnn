#include <Emdemnn/Emdemnn.h>

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
  std::shared_ptr<TestScreen> testScreen = entity->addComponent<TestScreen>();

  // Start the engine's main loop.
  core->start();

  return 0;
}