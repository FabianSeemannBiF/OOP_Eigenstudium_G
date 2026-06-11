//
// Created by Fabian on 6/11/26.
//

#ifndef OOP_EIGENSTUDIUM_G_CHARACTER_H
#define OOP_EIGENSTUDIUM_G_CHARACTER_H


class Character {
public:
    //Constructor and Deconstructor
    Character();
    ~Character();

    //Step 1 - Functions:
    void move(int x, int y);
    void takeDamage(int damage);
    void setCharacterRelics(int relics);
    int getCharacterRelics();
    bool isDefeated();
private:
    int health = 5;
    int relics = 0;
    int x = 0, y = 0;
};


#endif //OOP_EIGENSTUDIUM_G_CHARACTER_H
