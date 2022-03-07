#include "Utility.h"

#include "HelpfulItem.h"
#include "DefensiveItem.h"
#include "Character.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"
#include "Dwarf.h"


std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<HelpfulItem>(new HelpfulItem()) );
    }
    
    std::cout << "made " << items.size() << " helpful items" << std::endl;
    return items;
}

std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<DefensiveItem>(new DefensiveItem()) );
    }
    
    std::cout << "made " << items.size() << " defensive items" << std::endl;
    return items;
}

std::string getCharacterStats(Character* charName)
{
    std::string str;
    
    str += "    hitPoints: " + std::to_string(charName->getHP()) + "\n";
    str += "    armor: " + std::to_string(charName->getArmorLevel()) + "\n";
    str += "    attack damage: " + std::to_string(charName->getAttackDamage()) + "\n";
    str += "    is defending: " + std::string((charName->getIsDefending() ? "true" : "false" )) + "\n";
    str += "    " + std::to_string(charName->getHelpfulItems().size()) + " helpful items,  " + std::to_string(charName->getDefensiveItems().size()) + " defensive items";
    return str;
}

void useDefensiveItem(Character* charName, Item& item)
{
    //dwarves, paladins, and DragonSlayers get extra boosts from defensive item.
    if( auto* dwarf = dynamic_cast<Dwarf*>(charName) )
    {
        dwarf->boostArmor( item.getBoost() * 1.1 );
    }
    else if( auto* paladin = dynamic_cast<Paladin*>(charName) )
    {
        //same with paladins
        paladin->boostArmor( item.getBoost() * 1.3 );
    }
    else if( auto* dragonSlayer = dynamic_cast<DragonSlayer*>(charName))
    {
        dragonSlayer->boostArmor( item.getBoost() * 1.5 );
    }
    else if( auto* dragon = dynamic_cast<Dragon*>(charName) )
    {
        //dragons don't need defensive items
    }  
}
void useHelpfulItem(Character* charName, Item* item)
{
    if( auto* dwarf = dynamic_cast<Dwarf*>(charName) )
    {
        dwarf->boostHitPoints(item->getBoost() * 2);
    }
    else if( auto* paladin = dynamic_cast<Paladin*>(charName) )
    {
        paladin->boostHitPoints(item->getBoost() * 1.5);
    }
    else if( auto* dragonSlayer = dynamic_cast<DragonSlayer*>(charName))
    {
        dragonSlayer->boostHitPoints(item->getBoost() * 1.25);
    }
    else if( auto* dragon = dynamic_cast<Dragon*>(charName) )
    {
        //dragons don't carry helpful items!
    }
}
void useAttackItem(Character* charName, Item* item)
{
    if( auto* dwarf = dynamic_cast<Dwarf*>(charName) )
    {
        dwarf->boostAttackDamage(item->getBoost() * 1.5);
    }
    else if( auto* paladin = dynamic_cast<Paladin*>(charName) )
    {
        paladin->boostAttackDamage(item->getBoost() * 1.33);
    }
    else if( auto* dragonSlayer = dynamic_cast<DragonSlayer*>(charName))
    {
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so their attack item should boost their attack damage by a factor of 10
        //this means you need to GET the attack damage, multiply it by the item's boost, and BOOST the attackDamage with that multiplied value.  
        //check Character.h for available member functions you can use.

        dragonSlayer->boostAttackDamage(item->getBoost() * 1.1);
    }
    else if( auto* dragon = dynamic_cast<Dragon*>(charName) )
    {
        //dragons don't carry attack items!
    }
}
