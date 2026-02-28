#include <iostream>
#include "Battle.h"
#include "Archer.h"
#include "Healer.h"
#include "Mage.h"
#include "Tank.h"
#include "Thief.h"

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
