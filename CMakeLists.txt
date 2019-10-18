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
)

add_executable(sandbox
  src/sandbox/main.cpp
  src/sandbox/TestScreen.h
  src/sandbox/TestScreen.cpp
)
target_link_libraries(sandbox Emdemnn)
