#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Resources.h"
#include "Camera.h"
#include "Keyboard.h"

#include <GL/glew.h>

namespace Emdemnn
{
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

std::shared_ptr<Core> Core::initialize()
{
  // Auto create object on use.
  std::shared_ptr<Core> core = std::make_shared<Core>();
  
  
  // Sets boolean to false so engine isn't running when initialized.
  core->running = false;
  // Smart pointer for referencing itself.
  core->self = core;
  
  // Initialize Resources.
  core->resources = std::make_shared<Resources>();
  // Initialize Keyboard.
  core->keyboard = std::make_shared<Keyboard>();
  // Sets resources' core weak_ptr to core's self.
  core->resources->core = core->self;
  
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
  
  // Initialize context inside core.
  core->context = Context::initialize();
  
  /*
  // Open the OpenGL device.
  core->device = alcOpenDevice(NULL);
  
  if(!core->device)
  {
	throw Exception("Failed to open AL device.");
  }
  // Create the audio context on core initialization.
  core->audioContext = alcCreateContext(core->device, NULL);
  
   if(!core->audioContext)
  {
    alcCloseDevice(core->device);
	throw Exception("Failed to create the audio context.");
  }
  
  if(!alcMakeContextCurrent(core->audioContext))
  {
    alcDestroyContext(core->context);
	alcCloseDevice(core->device);
	throw Exception("
  }*/

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
	  else if(event.type == SDL_KEYDOWN)
	  {
        // Add keys int to Keyboard class.
        keyboard->keys.push_back(event.key.keysym.sym);
		// Add pressedKeys int to Keyboard class.
		keyboard->pressedKeys.push_back(event.key.keysym.sym);
	  }
	  else if(event.type == SDL_KEYUP)
	  {
	    // Add releasedKeys int to Keyboard class.
		keyboard->releasedKeys.push_back(event.key.keysym.sym);
		
		// Clear the keys for they have been released.
	    for(std::vector<int>::iterator it = keyboard->keys.begin(); it != keyboard->keys.end();)
		{
          if(*it == event.key.keysym.sym)
          {
            // Remove element from that vector, use returned iterator.
            it = keyboard->keys.erase(it);
          }
          else
          {
            // Iterates only when nothing is there to be deleted.
            it++;
          }
        }
      }
    }
	
    for(std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
    {
      (*it)->tick(); 
    }
    
    // Clear the pressedKeys for are only valid that frame.
    for(std::vector<int>::iterator it = keyboard->pressedKeys.begin(); it != keyboard->pressedKeys.end();)
    {
      if(*it == event.key.keysym.sym)
      {
        // Remove element from that vector, use returned iterator.
        it = keyboard->pressedKeys.erase(it);
      }
      else
      {
        // Iterates only when nothing is there to be deleted.
        it++;
      }
    }
	
    // Clear the releasedKeys for are only valid that frame.
    for(std::vector<int>::iterator it = keyboard->releasedKeys.begin(); it != keyboard->releasedKeys.end();)
    {
      if(*it == event.key.keysym.sym)
      {
        // Remove element from that vector, use returned iterator.
        it = keyboard->releasedKeys.erase(it);
        }
      else
      {
        // Iterates only when nothing is there to be deleted.
        it++;
      }
    }

    //keyboard->pressedKeys.clear();
    //keyboard->releasedKeys.clear();
	
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
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

std::shared_ptr<Context> Core::getContext()
{
  return context;
}

std::shared_ptr<Camera> Core::getCurrentCamera()
{
  return cameras.at(0);
}

std::shared_ptr<Keyboard> Core::getKeyboard()
{
  return keyboard;
}
}
