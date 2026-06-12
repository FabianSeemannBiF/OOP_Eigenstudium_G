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
void GameWorld::initGameWorld() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (i == 0 && j == 0) {
                this->board[i][j] = FieldType::EMPTY;
                continue;
            }

            const int random = rand() % 10;
            switch (random) {
                case 0 ... 3:
                    this->board[i][j] = FieldType::EMPTY;
                    break;
                case 4 ... 7:
                    this->board[i][j] = FieldType::DANGER;
                    break;
                case 8:
                    this->board[i][j] = FieldType::WELL;
                    break;
                case 9:
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
            this->board[randX][randY] = FieldType::RELIC;
            this->relics++;
        }
    }
}

GameWorld::GameWorld() {
    initGameWorld();
}

GameWorld::~GameWorld() = default;

void GameWorld::setField(int x, int y) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        this->board[y][x] = FieldType::EMPTY;
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

void GameWorld::printBoard(const int playerX, const int playerY) const {
    std::cout << "================== OASISCRAWLER ==================" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (j == playerX && i == playerY) {
                std::cout << "P";
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
    std::cout << "==================================================" << std::endl;
}

/**
 * ==================================================
 * STEP 2:
 * ==================================================
 */
