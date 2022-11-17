cmake_minimum_required(VERSION 3.23)
project(MenuS3projet C)

set(CMAKE_C_STANDARD 99)

add_executable(MenuS3projet main.c Menu.c Menu.h)

target_link_libraries(MenuS3projet -lmingw32 -lalleg44)