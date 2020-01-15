#include "MeshRenderer.h"
#include "Exception.h"
#include "Model.h"
#include "Material.h"
#include "Core.h"
#include "Entity.h"
#include "Camera.h"
#include "Transform.h"

namespace Emdemnn
{
void MeshRenderer::onInit()
{
  
}

void MeshRenderer::onDisplay()
{
  mesh->model->setTexture("u_Texture", material->texture);

  material->shader->setUniform("u_Projection", getCore()->getCurrentCamera()->getProjection());
  material->shader->setUniform("u_View", getCore()->getCurrentCamera()->getView());
  material->shader->setUniform("u_Model", getEntity()->getTransform()->getModel());
  
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
