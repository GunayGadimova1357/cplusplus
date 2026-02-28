

#ifndef MAGE_H
#define MAGE_H
#include "Character.h"


class Mage : public Character {
public:
    Mage();
    void defence() override;
    void attack() override;
    void use_skill(int skillIndex) override;
};



#endif //MAGE_H
