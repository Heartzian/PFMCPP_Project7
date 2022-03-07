#include "Item.h"
#include "Character.h"

Item::Item(const std::string& name_, int effect ) : name(name_), boost(effect) {}
Item::~Item() {}

const std::string& getName() 
{ 
    return name; 
}

int getBoost() const 
{ 
    return boost; 
}