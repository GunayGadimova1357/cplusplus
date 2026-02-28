
#include "Archer.h"

#include <iostream>

Archer::Archer() : Character(1, 0, 75, 4, 2, 0, 6) {}

void Archer::defence() {
    std::cout << "\nArcher defence: " << _defence << std::endl;
    _xp += 125;
    _hp -= 10;
}

void Archer::attack() {
    std::cout << "\nArcher attack: " << _attack << std::endl;
}

void Archer::use_skill(int skillIndex) {
    Skill* skill = getSkill(skillIndex);
    if (skill && skillIndex == 0) {
        std::cout << "Archer uses Piercing Arrow!" << std::endl;
        _attack += 2;
    } else {
        Character::use_skill(skillIndex);
    }
}
