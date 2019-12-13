#include "Model.h"
#include "Core.h"

namespace Emdemnn
{
void Model::onLoad(const std::string& path)
{
  model = getCore()->getContext()->createMesh();
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

    model->parse(obj);
  }
}
}
