cmake_minimum_required(VERSION 3.14)
project(Lab_9 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(Lab_9_1 Q1.c)
target_link_libraries(Lab_9_1 Threads::Threads)
add_executable(Lab_9_2 Q2.c)
