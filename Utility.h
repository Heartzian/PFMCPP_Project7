#pragma once

#include <vector>
#include <memory>
#include "Item.h"

struct Character;

std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num);
std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num);

std::string getCharacterStats(Character* charName);
void useDefensiveItem(Character*, Item&);
void useHelpfulItem(Character*, Item*);
void useAttackItem(Character*, Item*);
