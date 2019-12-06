#include "Mesh.h"

namespace Emdemnn
{
void Mesh::onLoad(const std::string& path)
{
  mesh = getCore->context->createMesh();
  {
    std::ifstream f(path);

    if(!f.is_open())
    {
      throw Exception("Failed to open model");
    }

    std::string obj;
    std::string line;

    while(!f.eof())
    {
      std::getline(f, line);
      obj += line + "\n";
    }

    mesh->parse(obj);
  }
}
}
