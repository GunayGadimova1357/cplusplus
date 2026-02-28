

#include "Battle.h"
#include <iostream>

    void Battle::start(Character& character1, Character& character2) {
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

    void Battle::  takeTurn(int turnCounter, Character& character1, Character& character2) {
        if (turnCounter == 1) {
            std::cout << "\nPlayer 1's turn:" << std::endl;
            performTurn(character1, character2);
        } else {
            std::cout << "\nPlayer 2's turn:" << std::endl;
            performTurn(character2, character1);
        }
    }


    void Battle::  performTurn(Character& attacker, Character& defender) {
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

