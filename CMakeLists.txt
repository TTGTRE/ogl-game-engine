cmake_minimum_required(VERSION 3.14)
project(OGLExperiments)

set(CMAKE_CXX_STANDARD 17)

add_executable(OGLExperiments Main.cpp Triple.cpp SquareEntity.cpp TextureUtils.h TextureUtils.cpp)

find_library(GLEW glew32.lib lib)
find_library(GLM glm_static.lib lib)
find_library(GLFW3 glfw3.lib lib)
find_library(SOIL2 soil2-debug.lib lib)

include_directories(include)

target_link_libraries(OGLExperiments ${GLEW} ${GLM} ${GLFW3} ${SOIL2} OpenGL32)
