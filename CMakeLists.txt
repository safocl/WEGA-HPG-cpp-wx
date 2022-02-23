cmake_minimum_required( VERSION 3.20 )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wformat -Wformat-security -pedantic -pedantic-errors -Werror)
add_compile_options(-fPIC -pie -fstack-protector)
add_compile_options(-pthread)
add_compile_options(-fstack-protector-strong)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=leak")

project( wega-hpg-cpp-wx LANGUAGES CXX )

message("module path is ${CMAKE_MODULE_PATH}")
find_package(wxWidgets REQUIRED core base )
include("${wxWidgets_USE_FILE}")

add_subdirectory( src )
