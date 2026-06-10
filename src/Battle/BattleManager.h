#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include <memory>
#include <vector>
#include "../character/Character.h"
#include "../mob/Mob.h"

enum class DefensePolicy {
    Balanced,
    Dodge,
    Block,
    Parry
};

class BattleManager {
public:
    BattleManager(Character& player, std::vector<std::unique_ptr<Mob>> mobs);
    bool run();

private:
    struct BattleActor {
        Character* character = nullptr;
        Mob* mob = nullptr;
        int remainingTime = 0;
        int stamina = 0;
        DefensePolicy defensePolicy = DefensePolicy::Balanced;

        bool isPlayer() const { return character != nullptr; }
        bool isAlive() const;
        std::string getName() const;
        int getCurrentHp() const;
        int getMaxHp() const;
        int getSpeed() const;
        int getMaxStamina() const;
        int getStaminaRegen() const;
        int getAgility() const;
        int getDefense() const;
        int getScalingStat(ScalingStat scalingStat) const;
        const std::vector<Skill>& getSkills() const;
        int getSkillMasteryLevel(const std::string& skillId) const;
        void gainSkillMastery(const std::string& skillId, int amount);
        void takeDamage(int damage);
    };

    Character& player;
    std::vector<std::unique_ptr<Mob>> mobs;
    std::vector<BattleActor> actors;

    void initializeActors();
    bool isBattleOver() const;
    bool playerWon() const;
    BattleActor* findReadyActor();
    void advanceTime();
    void takeTurn(BattleActor& actor);
    void playerTurn(BattleActor& actor);
    void mobTurn(BattleActor& actor);
    void resolveSkill(BattleActor& attacker, BattleActor& defender, const Skill& skill);
    void resolveRecover(BattleActor& actor, const Skill& skill);
    int calculateTimeCost(const BattleActor& actor, const Skill& skill) const;
    int calculateStaminaCost(const BattleActor& actor, const Skill& skill) const;
    int calculateDamage(const BattleActor& attacker, const BattleActor& defender, const Skill& skill) const;
    int applyDefense(BattleActor& attacker, BattleActor& defender, int damage);
    BattleActor* choosePlayerTarget();
    BattleActor* chooseMobTarget();
    const Skill* chooseMobSkill(const BattleActor& actor) const;
    void chooseDefensePolicy(BattleActor& actor);
    void printBattleStatus() const;
    bool rollPercent(int chance) const;
    int getExpReward() const;
};

#endif //BATTLEMANAGER_H
