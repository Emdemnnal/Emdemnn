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
  // TODO: Set this to onLoad stuff.
  material = getCore()->getResources()->context->createShader();
}

void MeshRenderer::onDisplay()
{
  // TODO: setUniforms here as well as the render() function call.
}

void MeshRenderer::setMesh()
{
  // TODO: do the setMesh of mesh from mesh class here after loaded.
}

void MeshRenderer::setMaterial()
{
  // TODO: do the setTexture of texture from texture class here after loaded.
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
