

#ifndef HEALER_H
#define HEALER_H

#include "Character.h"

class Healer : public Character {
public:
    Healer();
    void defence() override;
    void attack() override;
    void use_skill(int skillIndex) override;
};



#endif //HEALER_H
