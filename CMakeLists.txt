cmake_minimum_required(VERSION 3.10)
project(Veritas)

include_directories(includes)
file(GLOB Sources src/*.cpp)

add_library(Veritas STATIC ${Sources})

include_directories(includes/Dx)
target_link_directories(Veritas PUBLIC lib)
target_link_libraries(Veritas d3d9 d3dx9)

add_subdirectory(VeritasTest)
