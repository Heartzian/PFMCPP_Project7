#include "AttackItem.h"
#include "Utility.h"

AttackItem::~AttackItem() {}

void AttackItem::use(Character* charName)
{
    useAttackItem(charName, this);
}
