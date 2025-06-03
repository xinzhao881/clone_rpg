cmake_minimum_required(VERSION 3.31)
project(clone_rpg)

set(CMAKE_CXX_STANDARD 20)

add_executable(clone_rpg src/main.cpp
        src/stats/hp.h
        src/stats/hitpointtypes.h
        src/stats/hp.cpp
        src/character/warrior.h
        src/stats/statBlock.h
        src/character/Character.h
        src/character/warrior.cpp
        src/character/mage.h
        src/character/mage.cpp
)
