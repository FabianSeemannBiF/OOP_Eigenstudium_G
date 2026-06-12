//
// Created by Fabian on 6/11/26.
//

#include "../includes/GameWorld.h"

#include <cstdlib>
#include <iostream>
#include <ostream>

/**
 * ==================================================
 * STEP 1: Initialization of the Game Board
 * ==================================================
 */
void GameWorld::initGameWorld(const int difficulty) {
    this->relics = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (i == 0 && j == 0) {
                this->board[i][j] = FieldType::EMPTY;
                continue;
            }

            const int random = rand() % 100;

            int dangerLimit = 40 + (difficulty * 5);
            if (dangerLimit > 75) dangerLimit = 75;

            int range = 0;
            if (random < 40) {
                range = 1;
            } else if (random < dangerLimit) {
                range = 2;
            } else if (random < 90) {
                range = 3;
            } else {
                range = 4;
            }

            switch (range) {
                case 1:
                    this->board[i][j] = FieldType::EMPTY;
                    break;
                case 2:
                    this->board[i][j] = FieldType::DANGER;
                    break;
                case 3:
                    this->board[i][j] = FieldType::WELL;
                    break;
                case 4:
                    this->board[i][j] = FieldType::RELIC;
                    this->relics++;
                    break;
                default:
                    this->board[i][j] = FieldType::EMPTY;
                    break;
            }
        }
    }

    while (this->relics == 0) {
        const int randX = rand() % 5;
        const int randY = rand() % 5;

        if (randX != 0 || randY != 0) {
            this->board[randY][randX] = FieldType::RELIC;
            this->relics++;
        }
    }
}

GameWorld::GameWorld() {
    initGameWorld();
}

GameWorld::~GameWorld() = default;

void GameWorld::setField(int x, int y, FieldType type) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        this->board[y][x] = type;
    }
}

FieldType GameWorld::getField(int x, int y) const {
    if (x < 0 || x >= 5 || y < 0 || y >= 5) {
        return FieldType::EMPTY;
    }
    return static_cast<FieldType>(this->board[y][x]);
}

int GameWorld::getBoardRelics() const {
    return this->relics;
}

void GameWorld::printBoard(const int playerX, const int playerY, const int enemyX, const int enemyY) const {
    std::cout << "================== OASIS CRAWLER ==================" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (j == playerX && i == playerY) {
                std::cout << "P";
            } else if (j == enemyX && i == enemyY) {
                std::cout << "E";
            } else {
                const int field = this->board[i][j];
                switch (field) {
                    case FieldType::EMPTY:
                        std::cout << ".";
                        break;
                    case FieldType::DANGER:
                        std::cout << "D";
                        break;
                    case FieldType::WELL:
                        std::cout << "W";
                        break;
                    case FieldType::RELIC:
                        std::cout << "R";
                        break;
                    default:
                        std::cout << "?";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "===================================================" << std::endl;
}