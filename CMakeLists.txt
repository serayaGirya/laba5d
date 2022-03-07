cmake_minimum_required(VERSION 3.20)
project(Library1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Library1 main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/string/tasks/task1.h libs/data_structures/string/tasks/task2.h libs/data_structures/string/tasks/task3.h libs/data_structures/string/tasks/task4.h libs/data_structures/string/tasks/task5.h libs/data_structures/string/tasks/task6.h libs/data_structures/string/tasks/task7.h libs/data_structures/string/tasks/task8.h libs/data_structures/string/tasks/task9.h libs/data_structures/string/tasks/task10.h libs/data_structures/string/tasks/task11.h libs/data_structures/string/tasks/task12.h libs/data_structures/string/tasks/task13.h libs/data_structures/string/tasks/task14.h libs/data_structures/string/tasks/task15.h libs/data_structures/string/tasks/task16.h libs/data_structures/string/tasks/task17.h libs/data_structures/string/tasks/task18.h libs/data_structures/string/tasks/task19.h)

add_subdirectory(libs)
target_link_libraries(Library1 algorithms)
target_link_libraries(Library1 data_structures)