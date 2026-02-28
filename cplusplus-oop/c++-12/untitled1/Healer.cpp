
#include "Healer.h"
#include <iostream>

Healer::Healer() : Character(1, 0, 100, 3, 2, 50, 3) {}

void Healer::defence() {
    std::cout << "\nHealer defence: " << _defence << std::endl;
    _xp += 125;
}

void Healer::attack() {
    std::cout << "\nHealer attack: " << _attack << std::endl;
    _hp += 20;
}

void Healer::use_skill(int skillIndex) {
    Skill* skill = getSkill(skillIndex);
    if (skill && skillIndex == 0) {
        std::cout << "Healer uses Heal!" << std::endl;
        _hp += 15;
    } else {
        Character::use_skill(skillIndex);
    }
}
