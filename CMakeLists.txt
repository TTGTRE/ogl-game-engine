cmake_minimum_required(VERSION 3.14)
project(OGLExperiments)

set(CMAKE_CXX_STANDARD 17)

add_executable(OGLExperiments src/Main.cpp src/Triple.cpp src/Entity.cpp src/TextureUtils.cpp
        src/ShaderUtils.cpp src/model/ModelLoader.cpp src/model/Model.cpp src/Buffers.h src/Color.cpp src/SquareEntity.cpp src/GLUtilities.cpp src/Buffers.cpp src/WorldProperties.cpp src/WorldProperties.h)

find_library(GLEW glew32.lib lib)
find_library(GLM glm_static.lib lib)
find_library(GLFW3 glfw3.lib lib)
find_library(SOIL2 soil2-debug.lib lib)

include_directories(include)

target_link_libraries(OGLExperiments ${GLEW} ${GLM} ${GLFW3} ${SOIL2} OpenGL32)
