cmake_minimum_required(VERSION 4.2)
project(OOP_Eigenstudium_G)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(OOP_Eigenstudium_G
        includes/Character.h
        includes/GameWorld.h
        src/Character.cpp
        src/GameWorld.cpp
        main.cpp
)
