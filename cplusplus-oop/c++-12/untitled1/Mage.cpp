
#include "Mage.h"
#include <iostream>

Mage::Mage() : Character(1, 0, 25, 5, 1, 100, 0) {}

void Mage::defence() {
    std::cout << "\nMage defence: " << _defence << std::endl;
}

void Mage::attack() {
    _xp += 125;
    _mana -= 20;
    if (_mana <= 0) {
        _hp -= 5;
    }
    std::cout << "\nMage cast: " << _attack << std::endl;
}

void Mage::use_skill(int skillIndex) {
    Skill* skill = getSkill(skillIndex);
    if (skill && skillIndex == 0 && _mana >= 30) {
        std::cout << "Mage uses Fireball!" << std::endl;
        _mana -= 30;
    } else {
        Character::use_skill(skillIndex);
    }
}
