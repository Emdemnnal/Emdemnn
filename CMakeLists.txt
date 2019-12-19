cmake_minimum_required(VERSION 2.6)
project(Emdemnn)

include_directories(
  src
)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_library(Emdemnn
  src/Emdemnn/Core.h
  src/Emdemnn/Core.cpp
  src/Emdemnn/Component.h
  src/Emdemnn/Component.cpp
  src/Emdemnn/Entity.h
  src/Emdemnn/Entity.cpp
  src/Emdemnn/MeshRenderer.h
  src/Emdemnn/MeshRenderer.cpp
  src/Emdemnn/Exception.h
  src/Emdemnn/Exception.cpp
  src/Emdemnn/Transform.h
  src/Emdemnn/Transform.cpp
  src/Emdemnn/Camera.h
  src/Emdemnn/Camera.cpp
  src/Emdemnn/Rend.h
  src/Emdemnn/Resources.h
  src/Emdemnn/Resources.cpp
  src/Emdemnn/Resource.h
  src/Emdemnn/Resource.cpp
  src/Emdemnn/Model.h
  src/Emdemnn/Model.cpp
  src/Emdemnn/Material.h
  src/Emdemnn/Material.cpp
  src/Emdemnn/stb_image.h
)

target_link_libraries(Emdemnn SDL2 rend)

add_executable(sandbox
  src/sandbox/main.cpp
  src/sandbox/TestScreen.h
  src/sandbox/TestScreen.cpp
)
target_link_libraries(sandbox Emdemnn)
