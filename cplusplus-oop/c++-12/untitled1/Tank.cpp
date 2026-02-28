
#include "Tank.h"
Tank::Tank() : Character(1, 0, 100, 2, 5, 0, 1) {}

void Tank::defence() {
    std::cout << "\nTank defence: " << _defence << std::endl;
    _xp += 125;
    _hp -= 10;
}

void Tank::attack() {
    std::cout << "\nTank attack: " << _attack << std::endl;
}

void Tank::use_skill(int skillIndex) {
    Skill* skill = getSkill(skillIndex);
    if (skill && skillIndex == 0) {
        std::cout << "Tank uses Enrage!" << std::endl;
        _attack += 10;
    } else {
        Character::use_skill(skillIndex);
    }
}