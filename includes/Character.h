//
// Created by Fabian on 6/11/26.
//

#ifndef OOP_EIGENSTUDIUM_G_CHARACTER_H
#define OOP_EIGENSTUDIUM_G_CHARACTER_H
#include <string>

#include "GameWorld.h"


class Character {
public:
    //Constructor and Deconstructor
    Character();
    ~Character();

    //Step 1 - Functions:
    void move(const char input, GameWorld *world);
    void setCharacterRelics(int relics);
    int getCharacterRelics() const;
    bool isDefeated() const;

    //Getters
    int getHealth() const;
    int getPositionX() const;
    int getPositionY() const;

    //Step 2 - Functions
    void resetPosition();

    //Step 3 - Functions:
    void findItem(AttributeType attributeType, const std::string &itemName);
    bool useItemSlot(AttributeType attributeType);
    int getAttributeValue(AttributeType attributeType) const;
private:
    int health = 5;
    int relics = 0;
    int x = 0, y = 0;

    //Step 3:
    int strength, dexterity, wisdom;
    bool hasItem;
    AttributeType activeItemAttribute;
    std::string itemName;
};


#endif //OOP_EIGENSTUDIUM_G_CHARACTER_H
