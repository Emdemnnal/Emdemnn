cmake_minimum_required(VERSION 2.6)
project(Emdemnn)

include_directories(
  src
)

add_library(Emdemnn
  src/Emdemnn/Core.h
  src/Emdemnn/Core.cpp
  src/Emdemnn/Component.h
  src/Emdemnn/Component.cpp
  src/Emdemnn/Entity.h
  src/Emdemnn/Entity.cpp
  src/Emdemnn/TriangleRenderer.h
  src/Emdemnn/TriangleRenderer.cpp
  src/Emdemnn/Exception.h
  src/Emdemnn/Exception.cpp
  src/Emdemnn/Transform.h
  src/Emdemnn/Transform.cpp
  src/Emdemnn/Camera.h
  src/Emdemnn/Camera.cpp
)

target_link_libraries(Emdemnn SDL2 rend)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_executable(sandbox
  src/sandbox/main.cpp
  src/sandbox/TestScreen.h
  src/sandbox/TestScreen.cpp
)
target_link_libraries(sandbox Emdemnn)
