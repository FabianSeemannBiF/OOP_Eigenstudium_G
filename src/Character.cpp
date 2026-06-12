//
// Created by Fabian on 6/11/26.
//

#include "../includes/Character.h"

#include <iostream>
#include <ostream>

#include "GameWorld.h"

/**
 * ==================================================
 * STEP 1: Character Creation
 * ==================================================
 */

Character::Character() {
    this->health = 5;
    this->relics = 0;
    this->x = 0;
    this->y = 0;

    this->strength = 7;
    this->dexterity = 5;
    this->wisdom = 3;
    this->hasItem = false;
    this->activeItemAttribute = STRENGTH;
}

Character::~Character() {
}

void Character::move(const char input, GameWorld *world) {
    int moveX = this->x;
    int moveY = this->y;

    switch (input) {
        case 'w':
        case 'W': moveY--;
            break;
        case 'a':
        case 'A': moveX--;
            break;
        case 's':
        case 'S': moveY++;
            break;
        case 'd':
        case 'D': moveX++;
            break;
        default:
            std::cout << "Character::move(): Invalid input! (W, A, S, D)" << std::endl;
            break;
    }

    if (moveX < 0 || moveX >= 5 || moveY < 0 || moveY >= 5) {
        std::cout << "Character::move(): Invalid input! Cannot leave designated area" << std::endl;
        return;
    }

    this->x = moveX;
    this->y = moveY;

    const FieldType field = world->getField(this->x, this->y);

    switch (field) {
        case FieldType::EMPTY:
            std::cout << "Character::move(): FieldType::EMPTY" << std::endl;
            break;
        case FieldType::DANGER: {
            const AttributeType dangerType = static_cast<AttributeType>(rand() % 3);
            const int roll = (rand() % 10) + 1;

            if (dangerType == STRENGTH) {
                std::cout << "Character::move(): STRENGTH Trial" << std::endl;
                std::cout << "You roll a: " << roll << std::endl;

                if (roll <= this->getAttributeValue(STRENGTH)) {
                    std::cout << "Trial succeeded!" << std::endl;
                } else if (this->useItemSlot(STRENGTH)) {
                    std::cout << "Item negated damage!" << std::endl;
                } else {
                    this->health--;
                    std::cout << "Trial failed! Damage Taken! Health left: " << this->health << std::endl;
                }
            } else if (dangerType == DEXTERITY) {
                std::cout << "Character::move(): DEXTERITY Trial" << std::endl;
                std::cout << "You roll a: " << roll << std::endl;

                if (roll <= this->getAttributeValue(DEXTERITY)) {
                    std::cout << "Trial succeeded!" << std::endl;
                } else if (this->useItemSlot(DEXTERITY)) {
                    std::cout << "Item negated damage!" << std::endl;
                } else {
                    this->health--;
                    std::cout << "Trial failed! Damage Taken! Health left: " << this->health << std::endl;
                }
            } else if (dangerType == WISDOM) {
                std::cout << "Character::move(): WISDOM Trial" << std::endl;
                std::cout << "You roll a: " << roll << std::endl;

                if (roll <= this->getAttributeValue(WISDOM)) {
                    std::cout << "Trial succeeded!" << std::endl;
                } else if (this->useItemSlot(WISDOM)) {
                    std::cout << "Item negated damage!" << std::endl;
                } else {
                    this->health--;
                    std::cout << "Trial failed! Damage Taken! Health left: " << this->health << std::endl;
                }
            }
            break;
        }
        case FieldType::WELL: {
            std::cout << "Character::move(): FieldType::WELL" << std::endl;
            this->health++;
            std::cout << "Character::move(): Health restored! Health left: " << this->health << std::endl;

            if (rand() % 2 == 0) {
                const int itemType = rand() % 3;
                if (itemType == 0) findItem(STRENGTH, "STR Potion");
                if (itemType == 1) findItem(DEXTERITY, "DEX Potion");
                if (itemType == 2) findItem(WISDOM, "WIS Potion");
            }
            break;
        }
        case FieldType::RELIC: {
            std::cout << "Character::move(): FieldType::RELIC" << std::endl;
            this->relics++;
            std::cout << "Character::move(): Relic found! Relics collected: " << this->relics << std::endl;

            if (rand() % 2 == 0) {
                const int itemType = rand() % 3;
                if (itemType == 0) findItem(STRENGTH, "Sword");
                if (itemType == 1) findItem(DEXTERITY, "Daggers");
                if (itemType == 2) findItem(WISDOM, "Tome");
            }
            break;
        }
    }

    world->setField(this->x, this->y);
}

void Character::setCharacterRelics(const int relics) {
    this->relics = relics;
}

int Character::getCharacterRelics() const {
    return this->relics;
}

bool Character::isDefeated() const {
    if (this->health <= 0) {
        return true;
    }
    return false;
}

int Character::getHealth() const {
    return this->health;
}

int Character::getPositionX() const {
    return this->x;
}

int Character::getPositionY() const {
    return this->y;
}

/**
 * ==================================================
 * STEP 2: Enemy hunting the player
 * ==================================================
 */

void Character::resetPosition() {
    this->x = 0;
    this->y = 0;
}

/**
 * ==================================================
 * STEP 3: Attributes and Items
 * ==================================================
 */

void Character::findItem(const AttributeType attributeType, const std::string &itemName) {
    this->hasItem = true;
    this->activeItemAttribute = attributeType;
    this->itemName = itemName;
    std::cout << "Character::findItem(): Item name: " << this->itemName << std::endl;
}

bool Character::useItemSlot(const AttributeType attributeType) {
    if (this->hasItem && this->activeItemAttribute == attributeType) {
        this->hasItem = false;
        std::cout << "Character::useItemSlot(): Item used!" << std::endl;
        return true;
    }
    return false;
}

int Character::getAttributeValue(const AttributeType attributeType) const {
    switch (attributeType) {
        case STRENGTH:
            return this->strength;
        case DEXTERITY:
            return this->dexterity;
        case WISDOM:
            return this->wisdom;
    }
    return 0;
}
