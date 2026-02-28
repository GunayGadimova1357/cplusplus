

#ifndef BATTLE_H
#define BATTLE_H
#include "Character.h"


class Battle {
public:
    void start(Character& character1, Character& character2);

private:
    void takeTurn(int turnCounter, Character& character1, Character& character2);
    void performTurn(Character& attacker, Character& defender);
};



#endif //BATTLE_H
