
#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"

class Archer : public Character {
public:
    Archer();
    void defence() override;
    void attack() override;
    void use_skill(int skillIndex) override;
};

#endif //ARCHER_H
