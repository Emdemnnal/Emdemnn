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
  
  // Create a in-game objects.
  std::shared_ptr<Entity> entity = core->addEntity();
  std::shared_ptr<Entity> entityCat = core->addEntity();

  // Add components to it.
  std::shared_ptr<MeshRenderer> level = entity->addComponent<MeshRenderer>();
  std::shared_ptr<MeshRenderer> player = entityCat->addComponent<MeshRenderer>();
  
  //std::weak_ptr<TestScreen> testScreen = entity->addComponent<TestScreen>();
  //std::weak_ptr<TriangleRenderer> triangle = entity->addComponent<TriangleRenderer>();
  
  // Create Resources.
  std::shared_ptr<Model> mesh = core->getResources()->load<Model>("../sources/graveyard/graveyard.obj");
  std::shared_ptr<Material> material = core->getResources()->load<Material>("../sources/graveyard/graveyard.png", "../sources/shaders/shader.txt");
  std::shared_ptr<Model> mesh2 = core->getResources()->load<Model>("../sources/curuthers/curuthers.obj");
  std::shared_ptr<Material> material2 = core->getResources()->load<Material>("../sources/curuthers/Whiskers_diffuse.png", "../sources/shaders/shader.txt");
 
  // Set Resources.
  level->setMesh(mesh);
  level->setMaterial(material);
  player->setMesh(mesh2);
  player->setMaterial(material2);
  
  // Create Camera.
  std::shared_ptr<Entity> entityCamera = core->addEntity();
  std::shared_ptr<Camera> camera = entityCamera->addComponent<Camera>();
  entityCamera->getTransform()->setPosition(glm::vec3(0, 4, 10));

  entityCat->getTransform()->setPosition(glm::vec3(0, 0, -6));
  
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
