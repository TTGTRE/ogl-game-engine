cmake_minimum_required(VERSION 3.14)
project(OGLExperiments)

set(CMAKE_CXX_STANDARD 17)

add_executable(OGLExperiments main.cpp)

set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

find_library(GLEW glew32.lib PATHS ${LIB_DIR})
find_library(GLM glm_static.lib PATHS ${LIB_DIR})
find_library(GLFW libglfw3.a PATHS ${LIB_DIR})
find_library(SOIL2 libsoil2-debug.a PATHS ${LIB_DIR})
#find_library(IMAGE_DXT image_DXT.o PATHS ${LIB_DIR})
#find_library(IMAGE_HELPER image_helper.o PATHS ${LIB_DIR})
#find_library(SOIL2 SOIL2.o PATHS ${LIB_DIR})
#find_library(ETC1_UTILS etc1_utils.o PATHS ${LIB_DIR})

include_directories("include")

target_link_libraries(OGLExperiments ${GLEW} ${GLM} ${GLFW} ${SOIL2} OpenGL32)
