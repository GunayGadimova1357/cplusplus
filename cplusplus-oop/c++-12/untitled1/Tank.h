

#ifndef TANK_H
#define TANK_H
#include "Character.h"



class Tank : public Character {
public:
    Tank();
    void defence() override;
    void attack() override;
    void use_skill(int skillIndex) override;
};



#endif //TANK_H
