#include "Resource.h"

class Face;

class Mesh : public Resource
{
private:
  std::vector<Face> faces;
  bool dirty;
  
  std::shared_ptr<Mesh> create();
  std::shared_ptr<Mesh> load(std::string path);
  
public:
  ~Mesh();
  
  void addFace(Face& face);
  
  GLuint getId();
};

