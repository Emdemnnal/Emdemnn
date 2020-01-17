#include "Resource.h"

class Texture : public Resource
{
private:
  GLuint id;
  bool dirty;
  int type;
  
  std::shared_ptr<Texture> create(unsigned int width, unsigned int height);
  std::shared_ptr<Texture> load(std::string path);
  
public:
  ~Texture();
  
  void setPixel(unsigned int x, unsigned int y, vec3 colour);
  void setPixel(unsigned int x, unsigned int y, vec4 colour);
  
  GLuint getId();
};
