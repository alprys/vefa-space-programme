cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(alp)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

file(GLOB sources src/*.cc)

add_executable(alp ${sources})
target_include_directories(alp PRIVATE include)
target_link_libraries(alp ${Geant4_LIBRARIES})