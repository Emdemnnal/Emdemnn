#include "Camera.h"

void Camera::onInit()
{
  // Initialize as Identity Matrix first.
  projection = glm::mat4(1.0f);
  view = glm::mat4(1.0f);
  
  projection = glm::perspective(radians(65.0f), 1.0f, 0.1f, 100.0f);
  view = glm::inverse(getTransform()->getModel());
  
  getCore()->cameras.push_back(getEntity()->getComponent<Camera>());
}

glm::mat4 Camera::getView()
{
  return view;
}

glm::mat4 Camera::getProjection()
{
  return projection;
}
