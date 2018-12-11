cmake_minimum_required(VERSION 3.0.2)
project(minecraft)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
list(APPEND CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules")

find_package(OpenGL REQUIRED)
find_package(SFML REQUIRED window system graphics)
find_package(GLEW REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/include" "${SFML_INCLUDE_DIR}" "${OPENGL_INCLUDE_DIR}" "${GLEW_INCLUDE_DIR}")

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(minecraft "${SOURCES}")

target_link_libraries(minecraft "${SFML_LIBRARIES}" "${OPENGL_LIBRARIES}" "${GLEW_LIBRARIES}")
