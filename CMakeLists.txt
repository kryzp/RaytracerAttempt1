cmake_minimum_required(VERSION 3.21)
project(RayTracingOneWeekend)

set(CMAKE_CXX_STANDARD 20)

set(GLM_INCLUDE_DIRS "D:/_DEV/libs/glm/")
set(GLAD_INCLUDE_DIRS "D:/_DEV/libs/glad/include/")
set(SDL2_INCLUDE_DIRS "D:/_DEV/libs/SDL2-2.0.20/include/")
set(SDL2_LIBRARIES "D:/_DEV/libs/SDL2-2.0.20/lib/x64/SDL2.lib" "D:/_DEV/libs/SDL2-2.0.20/lib/x64/SDL2main.lib")

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/glad.c
    src/app.cpp
    src/input.cpp
    src/renderer_2d.cpp

    src/wrapper/image.cpp
    src/wrapper/texture.cpp
    src/wrapper/texture_mgr.cpp
    src/wrapper/shader.cpp
    src/wrapper/shader_mgr.cpp
    src/wrapper/framebuffer.cpp
    src/wrapper/vertex_array.cpp
    src/wrapper/vertex_buffer.cpp
    src/wrapper/index_buffer.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLAD_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})
