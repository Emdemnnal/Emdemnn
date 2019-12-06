#include "MeshRenderer.h"
#include "Exception.h"

namespace Emdemnn
{

const GLfloat positions[] = 
  {
  0.0f, 0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f
  };

  const GLfloat colors[] = 
  {
  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f
  };

  const GLchar *src =
  "\n#ifdef VERTEX\n" \
  "attribute vec2 a_Position;" \
  "attribute vec4 a_Color;" \
  ""\
  "uniform mat4 u_Projection;" \
  "" \
  "varying vec4 v_Color;" \
  "" \
  "void main()" \
  "{" \
  "  gl_Position = u_Projection * vec4(a_Position, -5, 1);" \
  "  v_Color = a_Color;" \
  "}" \
  "" \
  "\n#endif\n" \
  "\n#ifdef FRAGMENT\n" \
  "" \
  "varying vec4 v_Color;" \
  "" \
  "void main()" \
  "{" \
  "  gl_FragColor = v_Color;" \
  "}" \
  "" \
  "\n#endif\n";

void MeshRenderer::onInit()
{
  // Call createShader function from Core.
  material = getCore()->getResources()->context->createShader();
}

void MeshRenderer::onDisplay()
{
  
}

std::shared_ptr MeshRenderer::getMesh()
{
  return mesh;
}

std::shared_ptr MeshRenderer::getMaterial()
{
  return material;
}
}
