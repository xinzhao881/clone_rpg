#include "BattleManager.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <utility>

namespace {
constexpr int maxChance = 95;

int clampChance(int chance) {
    return std::clamp(chance, 0, maxChance);
}
}

BattleManager::BattleManager(Character& player, std::vector<std::unique_ptr<Mob>> mobs)
    : player(player), mobs(std::move(mobs)) {
    initializeActors();
}

bool BattleManager::BattleActor::isAlive() const {
    return isPlayer() ? character->isAlive() : mob->isAlive();
}

std::string BattleManager::BattleActor::getName() const {
    return isPlayer() ? character->getName() : mob->getName();
}

int BattleManager::BattleActor::getCurrentHp() const {
    return isPlayer() ? character->getCurrentHp() : mob->getCurrentHp();
}

int BattleManager::BattleActor::getMaxHp() const {
    return isPlayer() ? character->getMaxHp() : mob->getMaxHp();
}

int BattleManager::BattleActor::getSpeed() const {
    return isPlayer() ? character->getSpeed() : mob->getSpeed();
}

int BattleManager::BattleActor::getMaxStamina() const {
    return isPlayer() ? character->getMaxStamina() : mob->getMaxStamina();
}

int BattleManager::BattleActor::getStaminaRegen() const {
    return isPlayer() ? character->getStaminaRegen() : mob->getStaminaRegen();
}

int BattleManager::BattleActor::getAgility() const {
    return isPlayer() ? character->getAgility() : mob->getAgility();
}

int BattleManager::BattleActor::getDefense() const {
    return isPlayer() ? character->getDefense() : mob->getDefense();
}

int BattleManager::BattleActor::getScalingStat(ScalingStat scalingStat) const {
    if (scalingStat == ScalingStat::Intelligence) {
        return isPlayer() ? character->getIntelligence() : mob->getIntelligence();
    }
    return isPlayer() ? character->getStrength() : mob->getStrength();
}

const std::vector<Skill>& BattleManager::BattleActor::getSkills() const {
    return isPlayer() ? character->getSkills() : mob->getSkills();
}

int BattleManager::BattleActor::getSkillMasteryLevel(const std::string& skillId) const {
    return isPlayer() ? character->getSkillMasteryLevel(skillId) : mob->getSkillMasteryLevel(skillId);
}

void BattleManager::BattleActor::gainSkillMastery(const std::string& skillId, int amount) {
    if (isPlayer()) {
        character->gainSkillMastery(skillId, amount);
    } else {
        mob->gainSkillMastery(skillId, amount);
    }
}

void BattleManager::BattleActor::takeDamage(int damage) {
    if (isPlayer()) {
        character->takeDamage(damage);
    } else {
        mob->takeDamage(damage);
    }
}

void BattleManager::initializeActors() {
    actors.push_back(BattleActor{.character = &player, .stamina = player.getMaxStamina()});
    for (auto& mob : mobs) {
        actors.push_back(BattleActor{.mob = mob.get(), .stamina = mob->getMaxStamina()});
    }
}

bool BattleManager::run() {
    if (mobs.empty()) {
        std::cout << "전투할 적이 없습니다." << std::endl;
        return true;
    }
    for (const auto& mob : mobs) {
        std::cout << " " << mob->getName();
    }
    std::cout << "와 전투가 시작되었습니다." << std::endl;
    while (!isBattleOver()) {
        BattleActor* actor = findReadyActor();
        if (actor == nullptr) {
            advanceTime();
            continue;
        }
        takeTurn(*actor);
    }

    if (playerWon()) {
        std::cout << "전투에서 승리했습니다." << std::endl;
        int totalExp = 0;
        for (const auto& mob : mobs) {
            totalExp += mob->getExpReward();
        }
        std::cout << totalExp << " 경험치를 획득했습니다!" << std::endl;
        player.gainExp(totalExp);
        return true;
    }

    std::cout << "전투에서 패배했습니다." << std::endl;
    return false;
}

bool BattleManager::isBattleOver() const {
    return !player.isAlive() || playerWon();
}

bool BattleManager::playerWon() const {
    return std::all_of(mobs.begin(), mobs.end(), [](const auto& mob) {
        return !mob->isAlive();
    });
}

BattleManager::BattleActor* BattleManager::findReadyActor() {
    BattleActor* readyActor = nullptr;
    for (auto& actor : actors) {
        if (!actor.isAlive() || actor.remainingTime > 0) {
            continue;
        }
        if (readyActor == nullptr || actor.remainingTime < readyActor->remainingTime) {
            readyActor = &actor;
        }
    }
    return readyActor;
}

void BattleManager::advanceTime() {
    for (auto& actor : actors) {
        if (!actor.isAlive()) {
            continue;
        }
        actor.remainingTime -= actor.getSpeed();
        actor.stamina = std::min(actor.getMaxStamina(), actor.stamina + actor.getStaminaRegen());
    }
}

void BattleManager::takeTurn(BattleActor& actor) {
    if (actor.isPlayer()) {
        playerTurn(actor);
    } else {
        mobTurn(actor);
    }
}

void BattleManager::playerTurn(BattleActor& actor) {
    printBattleStatus();
    // chooseDefensePolicy(actor);

    const auto& skills = actor.getSkills();
    while (true) {
        std::cout << "\n사용할 스킬을 선택하세요." << std::endl;
        for (int i = 0; i < static_cast<int>(skills.size()); ++i) {
            const Skill& skill = skills[i];
            std::cout << i + 1 << ": " << skill.name
                      << " / 시간:" << calculateTimeCost(actor, skill)
                      << " / 스태미나:" << calculateStaminaCost(actor, skill)
                      << " / 숙련도:" << actor.getSkillMasteryLevel(skill.id)
                      << std::endl;
        }
        std::cout << "> ";

        int choice = 0;
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > static_cast<int>(skills.size())) {
            std::cout << "유효하지 않은 스킬입니다." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        const Skill& skill = skills[choice - 1];
        const int staminaCost = calculateStaminaCost(actor, skill);
        if (actor.stamina < staminaCost) {
            std::cout << "스태미나가 부족합니다." << std::endl;
            continue;
        }

        actor.stamina -= staminaCost;
        actor.remainingTime = calculateTimeCost(actor, skill);
        actor.gainSkillMastery(skill.id, 1);

        if (skill.type == SkillType::Damage) {
            BattleActor* target = choosePlayerTarget();
            if (target != nullptr) {
                resolveSkill(actor, *target, skill);
            }
        } else {
            resolveRecover(actor, skill);
        }
        return;
    }
}

void BattleManager::mobTurn(BattleActor& actor) {
    const Skill* skill = chooseMobSkill(actor);
    if (skill == nullptr) {
        actor.remainingTime = 60;
        return;
    }
    if (actor.stamina < calculateStaminaCost(actor, *skill)) {
        actor.remainingTime = 60;
        actor.stamina = std::min(actor.getMaxStamina(), actor.stamina + 10);
        std::cout << actor.getName() << "은 스태미나를 회복합니다." << std::endl;
        return;
    }

    actor.stamina -= calculateStaminaCost(actor, *skill);
    actor.remainingTime = calculateTimeCost(actor, *skill);
    actor.gainSkillMastery(skill->id, 1);

    if (skill->type == SkillType::Damage) {
        BattleActor* target = chooseMobTarget();
        if (target != nullptr) {
            resolveSkill(actor, *target, *skill);
        }
    } else {
        resolveRecover(actor, *skill);
    }
}

void BattleManager::resolveSkill(BattleActor& attacker, BattleActor& defender, const Skill& skill) {
    std::cout << attacker.getName() << "의 " << skill.name << "!" << std::endl;
    const int hitChance = clampChance(skill.accuracy + attacker.getAgility() - defender.getAgility());
    if (!rollPercent(hitChance)) {
        std::cout << defender.getName() << "에게 빗나갔습니다." << std::endl;
        return;
    }

    const int damage = applyDefense(attacker, defender, calculateDamage(attacker, defender, skill));
    if (damage <= 0) {
        return;
    }

    defender.takeDamage(damage);
    std::cout << defender.getName() << "에게 " << damage << " 피해를 입혔습니다." << std::endl;
}

void BattleManager::resolveRecover(BattleActor& actor, const Skill& skill) {
    const int recoverAmount = skill.basePower + actor.getSkillMasteryLevel(skill.id) / 2;
    actor.stamina = std::min(actor.getMaxStamina(), actor.stamina + recoverAmount);
    std::cout << actor.getName() << "은 숨을 고르고 스태미나를 " << recoverAmount << " 회복했습니다." << std::endl;
}

int BattleManager::calculateTimeCost(const BattleActor& actor, const Skill& skill) const {
    const int masteryReduction = actor.getSkillMasteryLevel(skill.id) / 5;
    return std::max(skill.minTimeCost, skill.baseTimeCost - masteryReduction);
}

int BattleManager::calculateStaminaCost(const BattleActor& actor, const Skill& skill) const {
    const int masteryReduction = actor.getSkillMasteryLevel(skill.id) / 5;
    return std::max(skill.minStaminaCost, skill.baseStaminaCost - masteryReduction);
}

int BattleManager::calculateDamage(const BattleActor& attacker, const BattleActor& defender, const Skill& skill) const {
    const int masteryBonus = attacker.getSkillMasteryLevel(skill.id) / 3;
    const int rawDamage = skill.basePower + attacker.getScalingStat(skill.scalingStat) / 2 + masteryBonus;
    return std::max(1, rawDamage - defender.getDefense());
}

int BattleManager::applyDefense(BattleActor& attacker, BattleActor& defender, int damage) {
    int dodgeChance = defender.getAgility() * 2;
    int blockChance = defender.getDefense() * 3;
    int parryChance = defender.getAgility() + defender.getDefense();

    switch (defender.defensePolicy) {
        case DefensePolicy::Dodge:
            dodgeChance += 20;
            blockChance -= 8;
            parryChance -= 8;
            break;
        case DefensePolicy::Block:
            blockChance += 20;
            dodgeChance -= 8;
            parryChance -= 8;
            break;
        case DefensePolicy::Parry:
            parryChance += 18;
            dodgeChance -= 8;
            blockChance -= 8;
            break;
        case DefensePolicy::Balanced:
            dodgeChance += 5;
            blockChance += 5;
            parryChance += 5;
            break;
    }

    if (rollPercent(clampChance(dodgeChance))) {
        std::cout << defender.getName() << "이 공격을 피했습니다." << std::endl;
        return 0;
    }

    if (rollPercent(clampChance(parryChance))) {
        const int counterDamage = std::max(1, defender.getAgility() / 2 + 1);
        attacker.takeDamage(counterDamage);
        std::cout << defender.getName() << "이 패리했습니다. 반격 피해: " << counterDamage << std::endl;
        return 0;
    }

    if (rollPercent(clampChance(blockChance))) {
        const int reduced = std::max(1, damage / 2);
        std::cout << defender.getName() << "이 공격을 막았습니다." << std::endl;
        return reduced;
    }

    return damage;
}

BattleManager::BattleActor* BattleManager::choosePlayerTarget() {
    std::vector<BattleActor*> targets;
    for (auto& actor : actors) {
        if (!actor.isPlayer() && actor.isAlive()) {
            targets.push_back(&actor);
        }
    }

    while (true) {
        std::cout << "공격할 대상을 선택하세요." << std::endl;
        for (int i = 0; i < static_cast<int>(targets.size()); ++i) {
            std::cout << i + 1 << ": " << targets[i]->getName()
                      << " HP " << targets[i]->getCurrentHp() << "/" << targets[i]->getMaxHp()
                      << std::endl;
        }
        std::cout << "> ";

        int choice = 0;
        std::cin >> choice;
        if (!std::cin.fail() && choice >= 1 && choice <= static_cast<int>(targets.size())) {
            return targets[choice - 1];
        }
        std::cout << "유효하지 않은 대상입니다." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

BattleManager::BattleActor* BattleManager::chooseMobTarget() {
    for (auto& actor : actors) {
        if (actor.isPlayer() && actor.isAlive()) {
            return &actor;
        }
    }
    return nullptr;
}

const Skill* BattleManager::chooseMobSkill(const BattleActor& actor) const {
    const Skill* fallback = nullptr;
    for (const auto& skill : actor.getSkills()) {
        if (fallback == nullptr) {
            fallback = &skill;
        }
        if (skill.type == SkillType::Damage && actor.stamina >= calculateStaminaCost(actor, skill)) {
            return &skill;
        }
    }
    for (const auto& skill : actor.getSkills()) {
        if (skill.type != SkillType::Damage && actor.stamina >= calculateStaminaCost(actor, skill)) {
            return &skill;
        }
    }
    return fallback;
}

void BattleManager::chooseDefensePolicy(BattleActor& actor) {
    // 일단 지금은 1(Balanced)로 하드코딩
    actor.defensePolicy = DefensePolicy::Balanced;
}

void BattleManager::printBattleStatus() const {
    std::cout << "\n------------------------------------" << std::endl;
    for (const auto& actor : actors) {
        if (!actor.isAlive()) {
            continue;
        }
        std::cout << actor.getName()
                  << " HP " << actor.getCurrentHp() << "/" << actor.getMaxHp()
                  << " ST " << actor.stamina << "/" << actor.getMaxStamina()
                  << " TIME " << std::max(0, actor.remainingTime)
                  << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}

bool BattleManager::rollPercent(int chance) const {
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    return distribution(generator) <= chance;
}

int BattleManager::getExpReward() const {

}
