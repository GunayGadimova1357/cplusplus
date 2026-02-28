
#include "Thief.h"
#include <iostream>

Thief::Thief() : Character(1, 0, 50, 3, 0, 0, 5) {}

void Thief::defence() {
    std::cout << "\nThief defence: " << _defence << std::endl;
}

void Thief::attack() {
    _xp += 125;
    std::cout << "\nThief attack: " << _attack << std::endl;
}

void Thief::use_skill(int skillIndex) {
    Skill* skill = getSkill(skillIndex);
    if (skill && skillIndex == 0) {
        std::cout << "Thief uses Stealth!" << std::endl;
        _agility += 5;
    } else {
        Character::use_skill(skillIndex);
    }
}
