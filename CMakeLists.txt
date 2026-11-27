cmake_minimum_required(VERSION 3.21)
project(GameplayBugFixes VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(GameplayBugFixes SHARED src/main.cpp)
setup_geode_mod(GameplayBugFixes)
