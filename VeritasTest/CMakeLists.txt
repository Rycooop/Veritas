cmake_minimum_required(VERSION 3.10)

include_directories(../includes)

file(GLOB Sources *.cpp)

add_executable(VeritasTest WIN32 ${Sources})
target_link_libraries(VeritasTest Veritas)