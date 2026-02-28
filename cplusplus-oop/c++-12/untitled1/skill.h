

#ifndef SKILL_H
#define SKILL_H



class Skill {
private:
    char* name;
    char* type;
    int manaCost;

public:
    Skill(const char* skillName, const char* skillType, int manaCost);
    ~Skill();

    const char* getName() const;
    int getManaCost() const;

};



#endif //SKILL_H
