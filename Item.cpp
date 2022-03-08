#include "Item.h"
#include "Character.h"

Item::Item(const std::string& name_, int effect ) : name(name_), boost(effect) {}
Item::~Item() {}
