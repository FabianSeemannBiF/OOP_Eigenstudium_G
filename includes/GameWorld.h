//
// Created by Fabian on 6/11/26.
//

#ifndef OOP_EIGENSTUDIUM_G_GAMEWORLD_H
#define OOP_EIGENSTUDIUM_G_GAMEWORLD_H

enum FieldType {
    EMPTY,
    DANGER,
    WELL,
    RELIC
};

enum AttributeType {
    STRENGTH,
    DEXTERITY,
    WISDOM
};

class GameWorld {
public:
    //Constructor and Deconstructor
    GameWorld();
    ~GameWorld();

    //Step 1 - Functions:
    void initGameWorld(int difficulty = 1);
    FieldType getField(int x, int y) const;
    void setField(int x, int y, FieldType field = FieldType::EMPTY);
    int getBoardRelics() const;
    void printBoard(int playerX, int playerY, int enemyX, int enemyY) const;
private:
    int board[5][5]{};
    int x{}, y{};
    int relics = 0;
};


#endif //OOP_EIGENSTUDIUM_G_GAMEWORLD_H
