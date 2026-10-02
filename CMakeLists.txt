cmake_minimum_required(VERSION 3.16)

project(game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(game ${SOURCES} main.cpp)

target_include_directories(game PRIVATE include)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)
target_link_libraries(game PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)
