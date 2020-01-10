#include <Emdemnn/Emdemnn.h>
#include "TestScreen.h"
//#include <Emdemnn/Emdemnn_Core.h>

#include <iostream>
#include <memory>

using namespace Emdemnn;

int main()
{
  // Initialize our engine.
  std::shared_ptr<Core> core = Core::initialize();
  std::cout << "Emdemnn Engine" << std::endl;
  
  // Create a single in-game object.
  std::shared_ptr<Entity> entity = core->addEntity();

  // Add a very simple component to it.
  std::shared_ptr<MeshRenderer> level = entity->addComponent<MeshRenderer>();
  //std::weak_ptr<TestScreen> testScreen = entity->addComponent<TestScreen>();
  //std::weak_ptr<TriangleRenderer> triangle = entity->addComponent<TriangleRenderer>();
  
  // Create Resources.
  std::shared_ptr<Model> mesh = core->getResources()->load<Model>("../sources/graveyard/graveyard.obj");
  level->setMesh(mesh);
  
  std::shared_ptr<Material> material = core->getResources()->load<Material>("../sources/graveyard/graveyard.png", "../sources/shaders/shader.txt");
  level->setMaterial(material);
  
  // Create Camera.
  std::shared_ptr<Entity> entityCamera = core->addEntity();
  std::shared_ptr<Camera> camera = entityCamera->addComponent<Camera>();
  entityCamera->getTransform()->setPosition(glm::vec3(0, 0, 10));
  
  // Start the engine's main loop.
  core->start();

  // triangle->getTransform()->setPosition(...)
  // triangle->getComponent<Transform>()->setPosition(...)
  // triangle->getComponent<MeshRenderer>()->setMesh(...)

/*
  std::shared_ptr<Foo> f = std::make_shared<TestFoo>();

  Foo* f = new TestFoo();
*/

  return 0;
}
