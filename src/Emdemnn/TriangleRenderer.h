#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Exception.h"

#include "Component.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class TriangleRenderer : public Component
{
private:
  SDL_Window *window;
  GLuint programId;
  GLuint vaoId;

  bool quit;
  
  void onDisplay();
 
public:
  ~TriangleRenderer();
  void onInit();
  
};
