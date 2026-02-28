
#include "skill.h"
#include <cstring>

Skill::Skill(const char* skillName, const char* skillType, int manaCost)
    : manaCost(manaCost) {
    name = new char[strlen(skillName) + 1];
    type = new char[strlen(skillType) + 1];
    strcpy(name, skillName);
    strcpy(type, skillType);
}

Skill::~Skill() {
    delete[] name;
    delete[] type;
}

const char* Skill::getName() const {
    return name;
}

int Skill::getManaCost() const {
    return manaCost;
}