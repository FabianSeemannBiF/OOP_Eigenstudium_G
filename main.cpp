//
// Created by Fabian on 6/11/26.
//

#include <iostream>
#include <ostream>

#include "Enemy.h"
#include "includes/Character.h"
#include "includes/GameWorld.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int difficulty = 5;

    GameWorld world;
    world.initGameWorld(difficulty);
    Character player;
    Enemy enemy(4,4);

    std::cout << "==================================================" << std::endl;
    std::cout << "========== WELCOME TO THE OASIS CRAWLER ==========" << std::endl;
    std::cout << "==================================================" << std::endl;

    bool running = true;
    while (running) {

        world.printBoard(player.getPositionX(), player.getPositionY(), enemy.getX(), enemy.getY());

        std::cout << "Difficulty: " << difficulty << std::endl;
        std::cout << "Player Health: " << player.getHealth() << std::endl;
        std::cout << "Player Relics: " << player.getCharacterRelics() << std::endl;

        std::cout << "Attributes:" << std::endl;
        std::cout << player.getAttributeValue(STRENGTH) << std::endl;
        std::cout << player.getAttributeValue(DEXTERITY) << std::endl;
        std::cout << player.getAttributeValue(WISDOM) << std::endl;

        if (player.isDefeated()) {
            std::cout << "========== GAME OVER ==========" << std::endl;
            std::cout << "Player Defeated" << std::endl;
            std::cout << "===============================" << std::endl;
            running = false;
        }

        if (player.getCharacterRelics() == world.getBoardRelics()) {
            difficulty++;
            std::cout << "========== VICTORY ==========" << std::endl;
            std::cout << "All relics have been found! Added difficulty: " << difficulty << std::endl;
            std::cout << "=============================" << std::endl;
            world.initGameWorld(difficulty);
            player.setCharacterRelics(0);
            player.resetPosition();
            enemy = Enemy(4,4);
            continue;
        }

        char input;
        bool validInput = false;

        while (!validInput) {
            std::cout << "Please select a valid movement (W, A, S, D): ";
            std::cin >> input;

            input = tolower(input);

            if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
                validInput = true;
            } else {
                std::cout << "Invalid input! (W, A, S, D)" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }

        std::cout << "==================================================" << std::endl;
        player.move(input, &world);
        std::cout << "==================================================" << std::endl;

        if (player.getCharacterRelics() != world.getBoardRelics() && !player.isDefeated()) {
            enemy.updatePosition(player.getPositionX(), player.getPositionY(), &world);
        }

        if (player.getPositionX() == enemy.getX() && player.getPositionY() == enemy.getY()) {
            std::cout << "\n[GAME OVER] The enemy has caught up!" << std::endl;
            break;
        }

        /*
        if (player.getPositionX() == enemy.getX() && player.getPositionY() == enemy.getY()) {
            std::cout << "\n[DAMAGE] The Enemy Attacked you!" << std::endl;

            player.takeDamage(3);
            enemy = Enemy(4, 4);
        }*/
    }

    std::cout << "Thank you for playing!" << std::endl;
    return 0;
}