add_library(DSDEngine STATIC
  # DSDEngine core engine files
  main.cpp
)

find_package(OpenGL REQUIRED)

#target_include_directories(PADEngine PUBLIC ${Vulkan_INCLUDE_DIRS})

target_include_directories(DSDEngine PUBLIC
    ${DSDEngine_SOURCE_DIR}/external/glfw-3.3.2/include
    ${DSDEngine_SOURCE_DIR}/external/glm-0.9.9.8/glm
)

target_link_libraries(DSDEngine
    OpenGL::GL
    glfw
    glm
)

set_property(DIRECTORY ${DSDEngine_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DSDEngine)