cmake_minimum_required(VERSION 3.31)
project(clone_rpg)

set(CMAKE_CXX_STANDARD 20)

add_executable(clone_rpg src/main.cpp
        src/stats/Hp.h
        src/stats/hitpointtypes.h
        src/stats/Hp.cpp
        src/character/warrior.h
        src/stats/statBlock.h
        src/character/Character.h
        src/character/warrior.cpp
        src/character/mage.h
        src/character/mage.cpp
        "src/gameManager/GameManager.h"
        "src/gameManager/GameManager.cpp"
        src/mob/Mob.h
        src/mob/Goblin.h
)
set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/src/gameManager)
file(COPY ${RESOURCE_DIR}/story.json DESTINATION ${CMAKE_BINARY_DIR})

