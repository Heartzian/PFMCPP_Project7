#pragma once
#include "Item.h"

struct AttackItem : Item
{
    AttackItem() : Item("attack item", 5) { }
    ~AttackItem() override;
        
    void use(Character*) override;
};
