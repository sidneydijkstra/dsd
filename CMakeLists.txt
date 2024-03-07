cmake_minimum_required(VERSION 3.14)
project(DSDEngine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#--------------------------------------------------------------------
# Build dependencies
#--------------------------------------------------------------------

# Disable unnecessary build options and prevent name clashes with PAD Engine's build targets.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw-3.3.10)
add_subdirectory(external/glew-cmake)
add_subdirectory(external/glm)
add_subdirectory(external/soil)

#--------------------------------------------------------------------
# Build DSD Engine
#--------------------------------------------------------------------

# add_subdirectory(project/src)

find_package(OpenGL REQUIRED)

include_directories(${DSDEngine_SOURCE_DIR}/project/src)


file(
	COPY ${DSDEngine_SOURCE_DIR}/project/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)

file(
	COPY ${DSDEngine_SOURCE_DIR}/project/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)


add_executable(DSDEngine
    ${DSDEngine_SOURCE_DIR}/project/src/main.cpp

    ${DSDEngine_SOURCE_DIR}/project/src/config.h

    ${DSDEngine_SOURCE_DIR}/project/src/material.h
    ${DSDEngine_SOURCE_DIR}/project/src/transform.h
    ${DSDEngine_SOURCE_DIR}/project/src/shader.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/shader.h
    ${DSDEngine_SOURCE_DIR}/project/src/renderable.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/renderable.h
    ${DSDEngine_SOURCE_DIR}/project/src/texturebuffer.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/texturebuffer.h
    ${DSDEngine_SOURCE_DIR}/project/src/mesh.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/mesh.h

    ${DSDEngine_SOURCE_DIR}/project/src/resourcemanager.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/resourcemanager.h

    ${DSDEngine_SOURCE_DIR}/project/src/input.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/input.h
    ${DSDEngine_SOURCE_DIR}/project/src/camera.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/camera.h
    
    ${DSDEngine_SOURCE_DIR}/project/src/renderer.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/renderer.h
    ${DSDEngine_SOURCE_DIR}/project/src/light.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/light.h
    ${DSDEngine_SOURCE_DIR}/project/src/core.cpp
    ${DSDEngine_SOURCE_DIR}/project/src/core.h
)

target_include_directories(DSDEngine PUBLIC
    ${DSDEngine_SOURCE_DIR}/external/glfw-3.3.10/include
    ${DSDEngine_SOURCE_DIR}/external/glew-cmake/include
    ${DSDEngine_SOURCE_DIR}/external/glm/glm
    ${DSDEngine_SOURCE_DIR}/external/soil/include
)

target_link_libraries(DSDEngine
    OpenGL::GL
    ${GLFW_LIBRARIES}
    libglew_static
    glfw
    glm
    soil
)

set_property(DIRECTORY ${DSDEngine_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DSDEngine)