#include "Paladin.h"

Paladin::Paladin(std::string charName, int hp, int armor) : Character(hp,armor,8),name(charName)
{
    helpfulItems = makeHelpfulItems(8);
    defensiveItems = makeDefensiveItems(6);
}

const std::string& Paladin::getName()
{
    return name;
}

std::string Paladin::getStats()
{
    return getCharacterStats(this);
}

void Paladin::attack(Character& other)
{
    Character::attack(other);
}