#pragma once
#include "Character.h"

struct Dragon : Character
{
    Dragon(std::string charName, int hp, int armor);
    std::string getStats() override;
    const std::string& getName() override;
    void attack(Character& other) override;

private:
    const std::string name;
};

