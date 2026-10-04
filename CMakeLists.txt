cmake_minimum_required(VERSION 3.16)

project(game CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(game ${SOURCES} main.cpp)

target_include_directories(game PRIVATE include)

# Use a system-installed SFML 3 if there is one (your Linux machine),
# otherwise download and build it (GitHub Actions, a Windows PC)
find_package(SFML 3 COMPONENTS Audio System QUIET)

if (NOT SFML_FOUND)
    include(FetchContent)
    set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
    set(BUILD_SHARED_LIBS OFF)
    set(SFML_BUILD_GRAPHICS OFF)
    set(SFML_BUILD_WINDOW OFF)
    set(SFML_BUILD_NETWORK OFF)
    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON)
    FetchContent_MakeAvailable(SFML)
endif()

if (MSVC)
  target_compile_options(game PRIVATE /utf-8)
endif()

target_link_libraries(game PRIVATE SFML::Audio SFML::System)
