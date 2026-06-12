//
// Created by Fabian on 6/12/26.
//

/**
 * ==================================================
 * STEP 2: Enemy that hunts the player
 * ==================================================
 */

#include "Enemy.h"

#include <cmath>
#include <math.h>

Enemy::Enemy(const int x, const int y) {
    this->x = x;
    this->y = y;
}

Enemy::~Enemy() {

}

void Enemy::updatePosition(const int playerX, const int playerY, const GameWorld *world) {
    int moveX = this->x;
    int moveY = this->y;

    const int diffX = playerX - this->x;
    const int diffY = playerY - this->y;

    if (std::abs(diffX) > abs(diffY)) {
        moveX += (diffX > 0) ? 1 : -1;
    } else if (diffY != 0){
        moveY += (diffY > 0) ? 1 : -1;
    }

    const FieldType targetField = world->getField(moveX, moveY);

    if (targetField == FieldType::EMPTY || targetField == FieldType::RELIC) {
        this->x = moveX;
        this->y = moveY;
    } else {
        moveX = this->x;
        moveY = this->y;

        if (std::abs(diffX) <= abs(diffY)) {
            moveX += (diffX > 0) ? 1 : -1;
        } else if (diffY != 0){
            moveY += (diffY > 0) ? 1 : -1;
        }

        if (world->getField(moveX, moveY) == FieldType::EMPTY) {
            this->x = moveX;
            this->y = moveY;
        }
    }
}

int Enemy::getX() const {
    return this->x;
}

int Enemy::getY() const {
    return this->y;
}
