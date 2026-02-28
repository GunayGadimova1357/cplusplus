
#ifndef CHARACTER_H
#define CHARACTER_H
#include "skill.h"


class Character {
protected:
    int _level;
    int _xp;
    int _hp;
    int _attack;
    int _defence;
    int _mana;
    int _agility;
    Skill** skills;
    int numSkills;
public:
    Character(int level, int xp, int hp, int attack, int defence, int mana, int agility);
    virtual ~Character();

    bool isAlive() const;
    void addSkill(Skill* skill);
    Skill* getSkill(int index) const;
    void stats() const;

    virtual void defence() = 0;
    virtual void attack() = 0;
    virtual void use_skill(int skillIndex);

};



#endif //CHARACTER_H
