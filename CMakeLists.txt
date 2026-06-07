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
        src/mob/Mob.cpp
        src/mob/Goblin.h
        src/Items/Item.h
        src/Items/Item.cpp
        src/Items/ItemFactory.h
        src/Items/Potion.h
        src/Items/Weapon/Weapon.h
        src/Items/Armor/Armor.h
        src/Items/Armor/Armor.cpp
        src/Items/Accessory.h
        src/Items/Equipment.h
        src/Items/Equipment.cpp
        src/character/Character.cpp
        src/Items/Weapon/Weapon.cpp
        src/Gold/Gold.h
        src/Gold/Gold.cpp
        src/mob/MobFactory.h
        src/Items/ItemFactory.cpp
        src/mob/MobFactory.cpp
        src/skills/Skill.h
        src/skills/Skill.cpp
        src/Battle/BattleManager.h
        src/Battle/BattleManager.cpp
        src/Shop/Shop.h
        src/Shop/Shop.cpp
        src/Story/StoryManager.cpp
        src/Story/StoryManager.h
        src/Common/GameState.h
)
set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
file(COPY ${RESOURCE_DIR}/GameManager/story.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${RESOURCE_DIR}/Items/Items.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${RESOURCE_DIR}/mob/mobs.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${RESOURCE_DIR}/skills/skills.json DESTINATION ${CMAKE_BINARY_DIR})

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${RESOURCE_DIR}/GameManager/story.json
                ${CMAKE_BINARY_DIR}/story.json
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${RESOURCE_DIR}/Items/Items.json
                ${CMAKE_BINARY_DIR}/Items.json
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${RESOURCE_DIR}/mob/mobs.json
                ${CMAKE_BINARY_DIR}/mobs.json
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${RESOURCE_DIR}/skills/skills.json
                ${CMAKE_BINARY_DIR}/skills.json
)
add_dependencies(clone_rpg copy_resources)
