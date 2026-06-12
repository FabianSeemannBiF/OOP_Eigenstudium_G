//
// Created by Fabian on 6/12/26.
//

#ifndef OOP_EIGENSTUDIUM_G_ENEMY_H
#define OOP_EIGENSTUDIUM_G_ENEMY_H
#include "GameWorld.h"

#endif //OOP_EIGENSTUDIUM_G_ENEMY_H

/**
 * ==================================================
 * STEP 2: Enemy that hunts the player
 * ==================================================
 */

class Enemy {
public:
    //Constructor and Deconstructor
    Enemy(int x, int y);
    ~Enemy();

    //Step 2 - Functions:
    void updatePosition(int playerX, int playerY, const GameWorld *game);

    //Getters
    int getX() const;
    int getY() const;
private:
    int x, y;
};
