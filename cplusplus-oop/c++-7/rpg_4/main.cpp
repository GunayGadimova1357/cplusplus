#include <iostream>
#include <cstring>

class Skill {
private:
    char* name;
    char* type;
    int manaCost;

public:
    Skill(const char* skillName, const char* skillType, int manaCost)
        : manaCost(manaCost) {
        name = new char[strlen(skillName) + 1];
        type = new char[strlen(skillType) + 1];
        strcpy(name, skillName);
        strcpy(type, skillType);
    }

    ~Skill() {
        delete[] name;
        delete[] type;
    }

    const char* getName() const { return name; }
    int getManaCost() const { return manaCost; }
};

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
    Character(int level, int xp, int hp, int attack, int defence, int mana, int agility)
        : skills(nullptr), numSkills(0), _level(level), _xp(xp), _hp(hp),
          _attack(attack), _defence(defence), _mana(mana), _agility(agility) {}

    virtual ~Character() {
        for (int i = 0; i < numSkills; ++i) {
            delete skills[i];
        }
        delete[] skills;
    }

    bool isAlive() const { return _hp > 0; }

    void addSkill(Skill* skill) {
        Skill** newSkills = new Skill*[numSkills + 1];
        for (int i = 0; i < numSkills; ++i) {
            newSkills[i] = skills[i];
        }
        newSkills[numSkills] = skill;
        delete[] skills;
        skills = newSkills;
        numSkills++;
    }

    Skill* getSkill(int index) const {
        if (index >= 0 && index < numSkills) {
            return skills[index];
        }
        return nullptr;
    }

    void stats() const {
        std::cout << "Level: " << _level << std::endl
                  << "HP: " << _hp << std::endl
                  << "XP: " << _xp << std::endl
                  << "Attack: " << _attack << std::endl
                  << "Defence: " << _defence << std::endl
                  << "Mana: " << _mana << std::endl
                  << "Agility: " << _agility << std::endl;
    }

    virtual void defence() {}
    virtual void attack() {}
    virtual void use_skill(int skillIndex) {
        Skill* skill = getSkill(skillIndex);
        if (skill && _mana >= skill->getManaCost()) {
            std::cout << "Using skill: " << skill->getName() << std::endl;
            _mana -= skill->getManaCost();
        } else if (skill) {
            std::cout << "Not enough mana to use " << skill->getName() << std::endl;
        }
    }
};

class Tank : public Character {
public:
    Tank() : Character(1, 0, 100, 2, 5, 0, 1) {}

    void defence() override {
        std::cout << "\nTank defence: " << _defence << std::endl;
        _xp += 125;
        _hp -= 10;
    }

    void attack() override {
        std::cout << "\nTank attack: " << _attack << std::endl;
    }

    void use_skill(int skillIndex) override {
        Skill* skill = getSkill(skillIndex);
        if (skill && skillIndex == 0) {
            std::cout << "Tank uses Enrage!" << std::endl;
            _attack += 10;
        } else {
            Character::use_skill(skillIndex);
        }
    }
};

class Mage : public Character {
public:
    Mage() : Character(1, 0, 25, 5, 1, 100, 0) {}

    void defence() override {
        std::cout << "\nMage defence: " << _defence << std::endl;
    }

    void attack() override {
        _xp += 125;
        _mana -= 20;
        if (_mana <= 0) {
            _hp -= 5;
        }
        std::cout << "\nMage cast: " << _attack << std::endl;
    }

    void use_skill(int skillIndex) override {
        Skill* skill = getSkill(skillIndex);
        if (skill && skillIndex == 0 && _mana >= 30) {
            std::cout << "Mage uses Fireball!" << std::endl;
            _mana -= 30;
        } else {
            Character::use_skill(skillIndex);
        }
    }
};

class Thief : public Character {
public:
    Thief() : Character(1, 0, 50, 3, 0, 0, 5) {}

    void defence() override {
        std::cout << "\nThief defence: " << _defence << std::endl;
    }

    void attack() override {
        _xp += 125;
        std::cout << "\nThief attack: " << _attack << std::endl;
    }

    void use_skill(int skillIndex) override {
        Skill* skill = getSkill(skillIndex);
        if (skill && skillIndex == 0) {
            std::cout << "Thief uses Stealth!" << std::endl;
            _agility += 5;
        } else {
            Character::use_skill(skillIndex);
        }
    }
};

class Archer : public Character {
public:
    Archer() : Character(1, 0, 75, 4, 2, 0, 6) {}

    void defence() override {
        std::cout << "\nArcher defence: " << _defence << std::endl;
        _xp += 125;
        _hp -= 10;
    }

    void attack() override {
        std::cout << "\nArcher attack: " << _attack << std::endl;
    }

    void use_skill(int skillIndex) override {
        Skill* skill = getSkill(skillIndex);
        if (skill && skillIndex == 0) {
            std::cout << "Archer uses Piercing Arrow!" << std::endl;
            _attack += 2;
        } else {
            Character::use_skill(skillIndex);
        }
    }
};

class Healer : public Character {
public:
    Healer() : Character(1, 0, 100, 3, 2, 50, 3) {}

    void defence() override {
        std::cout << "\nHealer defence: " << _defence << std::endl;
        _xp += 125;
    }

    void attack() override {
        std::cout << "\nHealer attack: " << _attack << std::endl;
        _hp += 20;
    }

    void use_skill(int skillIndex) override {
        Skill* skill = getSkill(skillIndex);
        if (skill && skillIndex == 0) {
            std::cout << "Healer uses Heal!" << std::endl;
            _hp += 15;
        } else {
            Character::use_skill(skillIndex);
        }
    }
};

class Battle {
public:
    void start(Character& character1, Character& character2) {
        int turnCounter = 1;
        while (character1.isAlive() && character2.isAlive()) {
            takeTurn(turnCounter, character1, character2);
            turnCounter = (turnCounter == 1) ? 2 : 1;
        }

        if (character1.isAlive()) {
            std::cout << "Character 1 wins the battle!" << std::endl;
        } else {
            std::cout << "Character 2 wins the battle!" << std::endl;
        }
    }

    void takeTurn(int turnCounter, Character& character1, Character& character2) {
        if (turnCounter == 1) {
            std::cout << "\nPlayer 1's turn:" << std::endl;
            performTurn(character1, character2);
        } else {
            std::cout << "\nPlayer 2's turn:" << std::endl;
            performTurn(character2, character1);
        }
    }

private:
    void performTurn(Character& attacker, Character& defender) {
        std::cout << "\nAttacker's stats:\n";
        attacker.stats();
        std::cout << "\nDefender's stats:\n";
        defender.stats();

        attacker.attack();
        if (defender.isAlive()) {
            defender.defence();
        }

        int skillChoice;
        std::cout << "Choose a skill to use (1 - Enrage(for Tank), 2 - Fireball(for Mage), 3 - Stealth(for Thief), 4 - Piercing Arrow(for Archer), 5 - Heal(for Healer)): ";
        std::cin >> skillChoice;

        switch (skillChoice) {
            case 1:
                attacker.use_skill(0);
                break;
            case 2:
                attacker.use_skill(1);
                break;
            case 3:
                attacker.use_skill(2);
                break;
            case 4:
                attacker.use_skill(3);
                break;
            case 5:
                attacker.use_skill(4);
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    }
};


int main() {
    int choice1, choice2;

    std::cout << "Select character class for Player 1 (1 - Tank, 2 - Mage, 3 - Thief, 4 - Archer, 5 - Healer): ";
    std::cin >> choice1;

    std::cout << "Select character class for Player 2 (1 - Tank, 2 - Mage, 3 - Thief, 4 - Archer, 5 - Healer): ";
    std::cin >> choice2;

    Character* player1 = nullptr;
    Character* player2 = nullptr;

    switch (choice1) {
        case 1: player1 = new Tank(); break;
        case 2: player1 = new Mage(); break;
        case 3: player1 = new Thief(); break;
        case 4: player1 = new Archer(); break;
        case 5: player1 = new Healer(); break;
        default: std::cout << "Invalid choice for Player 1!" << std::endl; return 1;
    }

    switch (choice2) {
        case 1: player2 = new Tank(); break;
        case 2: player2 = new Mage(); break;
        case 3: player2 = new Thief(); break;
        case 4: player2 = new Archer(); break;
        case 5: player2 = new Healer(); break;
        default: std::cout << "Invalid choice for Player 2!" << std::endl; delete player1; return 1;
    }
    
    player1->addSkill(new Skill("Enrage", "Buff", 10));
    player1->addSkill(new Skill("Fireball", "Damage", 30));
    player1->addSkill(new Skill("Stealth", "Buff", 15));
    player1->addSkill(new Skill("Piercing Arrow", "Damage", 25));
    player1->addSkill(new Skill("Heal", "Support", 20));

    player2->addSkill(new Skill("Enrage", "Buff", 10));
    player2->addSkill(new Skill("Fireball", "Damage", 30));
    player2->addSkill(new Skill("Stealth", "Buff", 15));
    player2->addSkill(new Skill("Piercing Arrow", "Damage", 25));
    player2->addSkill(new Skill("Heal", "Support", 20));

    Battle battle;
    battle.start(*player1, *player2);

    delete player1;
    delete player2;

    return 0;
}
