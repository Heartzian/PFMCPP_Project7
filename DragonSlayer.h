#pragma once
#include "Character.h"
#include "AttackItem.h"

struct DragonSlayer : Character
{
    DragonSlayer(std::string name, int hp, int armor);
    std::string getStats() override;
    const std::string& getName() override;
    void attack(Character& other) override;
private:
    const std::string name;
    std::unique_ptr<AttackItem> attackItem = std::make_unique<AttackItem>();
};
