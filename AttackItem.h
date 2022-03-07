#pragma once
#include "Item.h"

struct AttackItem : Item
{
    AttackItem() : Item("attack item", 10) { }
    ~AttackItem() override;
        
    void use(Character*) override;
};
