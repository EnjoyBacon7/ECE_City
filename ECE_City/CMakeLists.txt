cmake_minimum_required(VERSION 3.23)
project(ECE_City C)

set(CMAKE_C_STANDARD 99)

add_executable(ECE_City main.c extras.c extras.h boucleJeu.c boucleJeu.h initPartie.c initPartie.h structures.h menus.c menus.h affichage.c affichage.h)

target_link_libraries(ECE_City -lmingw32 -lalleg44)