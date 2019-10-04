cmake_minimum_required(VERSION 2.6)
project(Emdemnn)

add_library(Emdemnn
    src/Emdemnn/Core.cpp
)

add_executable(sandbox
    src/sandbox/main.cpp
)
target_link_libraries(sandbox Emdemnn)