#include <Emdemnn/Emdemnn.h>
#include "TestScreen.h"
//#include <Emdemnn/Emdemnn_Core.h>

#include <iostream>
#include <memory>

using namespace Emdemnn;

struct Player : Component
{
  void onTick()
  {
    if(getKeyboard()->isKey('w'))
    {
      getTransform()->translate(vec3(0, 0, -0.1f));
    }
	else if(getKeyboard()->isKey('s'))
    {
      getTransform()->translate(vec3(0, 0, 0.1f));
    }
	else if(getKeyboard()->isKey('a'))
    {
      getTransform()->translate(vec3(-0.1f, 0, 0));
    }
	else if(getKeyboard()->isKey('d'))
    {
      getTransform()->translate(vec3(0.1f, 0, 0));
    }
	else if(getKeyboard()->isKey(EM_Q))
    {
      getTransform()->rotate(vec3(0, 0.04f, 0));
    }
	else if(getKeyboard()->isKey(EM_E))
    {
      getTransform()->rotate(vec3(0, -0.04f, 0));
    }
	
  }
};

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
  std::shared_ptr<Player> p = entityCamera->addComponent<Player>();
  entityCamera->getTransform()->setPosition(vec3(0, 3, 10));

  entityCat->getTransform()->setPosition(vec3(0, 1.7, -4));
  entityCat->getTransform()->setScale(vec3(0.7, 0.7, 0.7));
  
  // Start the engine's main loop.
  core->start();

  return 0;
}
