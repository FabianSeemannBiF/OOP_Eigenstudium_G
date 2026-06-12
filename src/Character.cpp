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

    if (moveX < 0 || moveX > 5 || moveY < 0 || moveY > 5) {
        std::cout << "Character::move(): Invalid input! Cannot leave designated area" << std::endl;
    }

    this->x = moveX;
    this->y = moveY;

    const FieldType field = world->getField(this->x, this->y);

    switch (field) {
        case FieldType::EMPTY:
            std::cout << "Character::move(): FieldType::EMPTY" << std::endl;
            break;
        case FieldType::DANGER:
            std::cout << "Character::move(): FieldType::DANGER" << std::endl;
            if (rand() % 6 == 0) {
                this->health--;
                std::cout << "Character::move(): Health changed! Health left: " << this->health << std::endl;
            } else {
                std::cout << "Character::move(): Nothing Happened!" << std::endl;
            }
            break;
        case FieldType::WELL:
            std::cout << "Character::move(): FieldType::WELL" << std::endl;
            this->health++;
            std::cout << "Character::move(): Health restored! Health left: " << this->health << std::endl;
            break;
        case FieldType::RELIC:
            std::cout << "Character::move(): FieldType::RELIC" << std::endl;
            this->relics++;
            std::cout << "Character::move(): Relic found! Relics collected: " << this->relics << std::endl;
            break;
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