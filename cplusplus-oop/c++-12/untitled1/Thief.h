
#ifndef THIEF_H
#define THIEF_H
#include "Character.h"

class Thief : public Character {
public:
    Thief();
    void defence() override;
    void attack() override;
    void use_skill(int skillIndex) override;
};




#endif //THIEF_H
