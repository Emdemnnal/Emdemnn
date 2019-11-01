#include "Core.h"
#include "Entity.h"

#include <GL/glew.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

std::shared_ptr<Core> Core::initialize()
{
  std::shared_ptr<Core> core = std::make_shared<Core>();
  core->running = false;
  core->self = core;
  
  // Create a window output for the engine.  
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::exception();
  }
  
  core->window = SDL_CreateWindow("Emdemnn",
  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL); 

  if(!SDL_GL_CreateContext(core->window))
  {
    throw std::exception();
  }

  if(glewInit() != GLEW_OK)
  {
    throw std::exception();
  }

  return core;
}

void Core::start()
{
  running = true;
  while(running != false)
  {
    SDL_Event event = {0};

    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        running = false;
      }
    }
    
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
    {
      (*it)->tick(); 
    }

    for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); ++it)
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
  std::shared_ptr<Entity> entity = std::make_shared<Entity>();
  entities.push_back(entity);
  
  entity->self = entity;
  entity->core = self;

  return entity;
}
