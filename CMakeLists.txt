cmake_minimum_required(VERSION 3.14)
project(OGLExperiments)

set(CMAKE_CXX_STANDARD 17)

add_executable(OGLExperiments main.cpp GLUtilities.cpp GLUtilities.h engine/Model.cpp engine/Model.h engine/DrawHandle.cpp engine/DrawHandle.h engine/ShaderHandle.cpp engine/ShaderHandle.h)

set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

find_library(GLEW glew32.lib PATHS ${LIB_DIR})
find_library(GLM glm_static.lib PATHS ${LIB_DIR})
find_library(GLFW libglfw3.a PATHS ${LIB_DIR})

include_directories("include")

target_link_libraries(OGLExperiments ${GLEW} ${GLM} ${GLFW} OpenGL32)
