#include "TriangleRenderer.h"
#include "Exception.h"

namespace Emdemnn
{
	
const GLchar *src =
  "\n#ifdef VERTEX\n" \
  "attribute vec3 a_Position;" \
  "" \
  "void main()" \
  "{" \
  "  gl_Position = vec4(a_Position, 1);" \
  "}" \
  "" \
  "\n#endif\n" \
  "\n#ifdef FRAGMENT\n" \
  "" \
  "void main()" \
  "{" \
  "  gl_FragColor = vec4(1, 0, 0, 1);" \
  "}" \
  "" \
  "\n#endif\n";
  
void TriangleRenderer::onInit()
{
  context->Context::initialize();
  shader = context->createShader();
  // Pass the "src" file into parse.
  shader->parse(src);
  
  // Preparing to add data.
  buffer = context->createBuffer();
  // Position primitive data.
  buffer->add(vec3(0, 0.5f, 0.0f));
  buffer->add(vec3(-0.5f, -0.5f, 0.0f));
  buffer->add(vec3(0.5f, -0.5f, 0.0f));
}

void TriangleRenderer::onDisplay()
{
  shader->setAttribute("a_Position", buffer);
  shader->render();
}
}
