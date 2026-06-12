//
// Created by Fabian on 6/11/26.
//

#include <iostream>
#include <ostream>

#include "includes/Character.h"
#include "includes/GameWorld.h"

int main() {
    GameWorld world;
    Character player;

    std::cout << "==================================================" << std::endl;
    std::cout << "========== WELCOME TO THE OASIS CRAWLER ==========" << std::endl;
    std::cout << "==================================================" << std::endl;

    bool running = true;
    while (running) {

        world.printBoard(player.getPositionX(), player.getPositionY());

        std::cout << "Player Health: " << player.getHealth() << std::endl;
        std::cout << "Player Relics: " << player.getCharacterRelics() << std::endl;

        if (player.isDefeated()) {
            std::cout << "========== GAME OVER ==========" << std::endl;
            std::cout << "Player Defeated" << std::endl;
            std::cout << "===============================" << std::endl;
            running = false;
        }

        if (player.getCharacterRelics() == world.getBoardRelics()) {
            std::cout << "========== VICTORY ==========" << std::endl;
            std::cout << "All relics have been found" << std::endl;
            std::cout << "=============================" << std::endl;
            running = false;
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
    }

    std::cout << "Thank you for playing!" << std::endl;
    return 0;
}