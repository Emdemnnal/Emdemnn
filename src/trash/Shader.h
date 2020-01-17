#include "Resource.h"

class Texture;

class Shader : public Resource
{
private:
  GLuint int;
  
  std:shared_ptr<Shader> create(std::string vertSrc, std::string fragSrc);
  std::shared_ptr<Shader> load(std::string path);
  
public:
  ~Shader();
  
  void setUniform(std::string name, float value);
  void setUniform(std::string name, std::weak_ptr<Texture> value);
  void setUniform(std::string name, mat4 value);
  void setUniform(std::string name, vec3 value);
  
  GLuint getId();
};
