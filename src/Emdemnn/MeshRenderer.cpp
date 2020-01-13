#include "MeshRenderer.h"
#include "Exception.h"
#include "Model.h"
#include "Material.h"
#include "Core.h"
#include "Entity.h"
#include "Camera.h"

namespace Emdemnn
{
void MeshRenderer::onInit()
{
  
}

void MeshRenderer::onDisplay()
{
  //angle += 0.1f;
  
  mesh->model->setTexture("u_Texture", material->texture);

  // material->shader->setUniform("u_Projection", glm::perspective(radians(65.0f), 1.0f, 0.1f, 100.0f));
  material->shader->setUniform("u_Projection", getCore()->getCurrentCamera()->getProjection());
  // material->shader->setUniform("u_View", getCore()->getCurrentCamera()->getView());
  material->shader->setUniform("u_Model",
    rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1, 0, 0)) *
    rotate(glm::mat4(1.0f), glm::radians(0.1f), glm::vec3(0, 1, 0)) *
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
