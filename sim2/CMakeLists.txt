cmake_minimum_required(VERSION 3.16...3.21)

project(Simulation)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(sim2 sim2.cc ${sources} ${headers})
target_link_libraries(sim2 ${Geant4_LIBRARIES})

add_custom_target(simulation DEPENDS sim2)
