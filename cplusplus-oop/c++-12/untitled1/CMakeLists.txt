cmake_minimum_required(VERSION 3.29)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        skill.cpp
        skill.h
        Character.cpp
        Character.h
        Battle.cpp
        Battle.h
        Tank.cpp
        Tank.h
        Mage.cpp
        Mage.h
        Thief.cpp
        Thief.h
        Archer.cpp
        Archer.h
        Healer.cpp
        Healer.h
)
