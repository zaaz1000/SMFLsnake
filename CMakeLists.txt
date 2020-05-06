cmake_minimum_required(VERSION 3.1)
project(SnakeOneWindow)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra)

set( SFML_STATIC_LIBRARIES TRUE)

set ( SFML_DIR "C:/cpp/SFML-2.5.1/lib/cmake/SFML/")

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(SnakeOneWindow main.cpp Game.cpp Menu.cpp)

target_link_libraries(SnakeOneWindow sfml-graphics sfml-audio )