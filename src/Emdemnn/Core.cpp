#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include <GL/glew.h>

namespace Emdemnn
{

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

std::shared_ptr<Core> Core::initialize()
{
  // Auto create object on use.
  std::shared_ptr<Core> core = std::make_shared<Core>();
  // Initialize context inside core.
  core->context = Context::initialize();
  // Sets boolean to false so engine isn't running when initialized.
  core->running = false;
  // Smart pointer for referencing itself.
  core->self = core;
  
  // Create a window output for the engine.  
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::exception();
  }
  
  core->window = SDL_CreateWindow("Emdemnn",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL); 

  if(!core->window)
  {
    throw Exception("Failed to create SDL window");	  
  }

  core->glContext = SDL_GL_CreateContext(core->window);
  
  if(!core->glContext)
  {
    throw Exception("Failed to create the OpenGL context");
  }

/*
  if(!SDL_GL_CreateContext(core->window))
  {
    throw std::exception();
  }

  if(glewInit() != GLEW_OK)
  {
    throw std::exception();
  }
*/

  core->context = Context::initialize();

  return core;
}

Core::~Core()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Core::start()
{
  running = true;
  while(running)
  {
    SDL_Event event = {0};

    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        running = false;
      }
    }
    
    for(std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
    {
      (*it)->tick(); 
    }

    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
    {
      (*it)->display(); 
    }

    SDL_GL_SwapWindow(window);
  }
}

void Core::stop()
{
    running = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
  // Auto create object on use.
  std::shared_ptr<Entity> entity = std::make_shared<Entity>();
  // Add it to list of entities on Core.
  entities.push_back(entity);
  
  // Stores pointer to itself.
  entity->self = entity;
  // Set Entity's core weak_ptr to core's self.
  entity->core = self;
  // Add a component transform to each entity.
  entity->transform = entity->addComponent<Transform>();

  return entity;
}

std::shared_ptr<Resources> Core::getResources()
{
  return resources;
}
}
