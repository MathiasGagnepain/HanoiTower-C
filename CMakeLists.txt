# How to use with mingw: (Windows)
#   cmake -S . -B Build -G "MinGW Makefiles"
#   cd Build
#   mingw32-make

# How to use with msys2: (Windows)
#   cmake -S . -B Build -G "MSYS Makefiles"
#   cd Build
#   make
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_C_COMPILER "gcc")

project(
  Hanoi-Tower
  VERSION 0.0.1
  LANGUAGES CXX C
)

find_package(Threads REQUIRED)

add_executable(hanoiTower
  src/main.c
)

target_include_directories(hanoiTower
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# target_compile_options(hanoiTower
#   PRIVATE
#     -Wall -Wextra -pedantic -g -O2
# )

set_target_properties(hanoiTower
  PROPERTIES
    C_STANDARD 99
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)