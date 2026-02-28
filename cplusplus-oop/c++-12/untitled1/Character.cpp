#include "Character.h"


#include <iostream>


Character::Character(int level, int xp, int hp, int attack, int defence, int mana, int agility)
    : skills(nullptr), numSkills(0), _level(level), _xp(xp), _hp(hp),
      _attack(attack), _defence(defence), _mana(mana), _agility(agility) {}

Character::~Character() {
    for (int i = 0; i < numSkills; ++i) {
        delete skills[i];
    }
    delete[] skills;
}

bool Character::isAlive() const {
    return _hp > 0;
}

void Character::addSkill(Skill* skill) {
    Skill** newSkills = new Skill*[numSkills + 1];
    for (int i = 0; i < numSkills; ++i) {
        newSkills[i] = skills[i];
    }
    newSkills[numSkills] = skill;
    delete[] skills;
    skills = newSkills;
    numSkills++;
}

Skill* Character::getSkill(int index) const {
    return (index >= 0 && index < numSkills) ? skills[index] : nullptr;
}

void Character::stats() const {
    std::cout << "Level: " << _level << std::endl
              << "HP: " << _hp << std::endl
              << "XP: " << _xp << std::endl
              << "Attack: " << _attack << std::endl
              << "Defence: " << _defence << std::endl
              << "Mana: " << _mana << std::endl
              << "Agility: " << _agility << std::endl;
}

void Character::use_skill(int skillIndex) {
    Skill* skill = getSkill(skillIndex);
    if (skill && _mana >= skill->getManaCost()) {
        _mana -= skill->getManaCost();
    } else if (skill) {
        return;
    }
}
