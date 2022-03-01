cmake_minimum_required(VERSION 3.20)
project(Library1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Library1 main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/string/tasks/task2.h libs/data_structures/string/tasks/task3.h)

add_subdirectory(libs)
target_link_libraries(Library1 algorithms)
target_link_libraries(Library1 data_structures)