#include "MeshRenderer.h"
#include "Exception.h"
#include "Model.h"
#include "Material.h"

namespace Emdemnn
{
  const GLchar *src =
  "#ifdef VERTEX                                 \n" \
  "                                              \n" \
  "attribute vec3 a_Position;                    \n" \
  "attribute vec2 a_TexCoord;                    \n" \
  "attribute vec3 a_Normal;                      \n" \
  "                                              \n" \
  "uniform mat4 u_Projection;                    \n" \
  "uniform mat4 u_Model;                         \n" \
  "                                              \n" \
  "varying vec3 v_Normal;                        \n" \
  "varying vec2 v_TexCoord;                      \n" \
  "                                              \n" \
  "void main()                                   \n" \
  "{                                             \n" \
  "  gl_Position = u_Projection *                \n" \
  "    u_Model * vec4(a_Position, 1);            \n" \
  "                                              \n" \
  "  v_Normal = a_Normal;                        \n" \
  "  v_TexCoord = a_TexCoord;                    \n" \
  "}                                             \n" \
  "                                              \n" \
  "#endif                                        \n" \
  "#ifdef FRAGMENT                               \n" \
  "                                              \n" \
  "uniform sampler2D u_Texture;                  \n" \
  "                                              \n" \
  "varying vec3 v_Normal;                        \n" \
  "varying vec2 v_TexCoord;                      \n" \
  "                                              \n" \
  "void main()                                   \n" \
  "{                                             \n" \
  "  gl_FragColor = texture2D(u_Texture, v_TexCoord);      \n" \
  "  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
  "}                                             \n" \
  "                                              \n" \
  "#endif                                        \n";

void MeshRenderer::onInit()
{
  
}

void MeshRenderer::onDisplay()
{
  angle += 0.1f;
  
  mesh->model->setTexture("u_Texture", material->texture);

  material->shader->setUniform("u_Projection", glm::perspective(radians(65.0f), 1.0f, 0.1f, 100.0f));
  material->shader->setUniform("u_Model",
    rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1, 0, 0)) *
    rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0, 1, 0)) *
    translate(glm::mat4(1.0f), glm::vec3(5, -2, 45))
  );
  material->shader->setMesh(mesh->model);
  material->shader->render();
  
}

void MeshRenderer::setMesh(std::shared_ptr<Model> _mesh)
{
  mesh = _mesh;
}

void MeshRenderer::setMaterial(std::shared_ptr<Material> _material)
{
  material = _material;
}

std::shared_ptr<Model> MeshRenderer::getMesh()
{
  return mesh;
}

std::shared_ptr<Material> MeshRenderer::getMaterial()
{
  return material;
}
}
