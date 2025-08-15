// **************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/01/01 00:00:00 by your_login       #+#    #+#             //
//   Updated: 2024/01/01 00:00:00 by your_login      ###   ########.fr       //
//                                                                            //
// **************************************************************************** //

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void printSeparator(const std::string& testName) {
	std::cout << "\n" << std::string(60, '=') << std::endl;
	std::cout << "         " << testName << std::endl;
	std::cout << std::string(60, '=') << std::endl;
}

void printStatus(const ClapTrap& trap, const std::string& type = "ClapTrap") {
	std::cout << type << " " << trap.getName() << " - HP: " << trap.getHitPoints()
			  << " | EP: " << trap.getEnergyPoints()
			  << " | AD: " << trap.getAttackDamage() << std::endl;
}

int main(void) {
	printSeparator("CONSTRUCTION/DESTRUCTION ORDER TESTS");

	std::cout << "\n--- Creating ScavTrap (should call ClapTrap first) ---" << std::endl;
	{
		ScavTrap scav("Guardian");
		printStatus(scav, "ScavTrap");
		std::cout << "\n--- Leaving scope (ScavTrap destructor first, then ClapTrap) ---" << std::endl;
	}

	printSeparator("ORTHODOX CANONICAL FORM TESTS");

	// Test default constructor
	std::cout << "\n--- Default Constructor ---" << std::endl;
	ScavTrap defaultScav;
	printStatus(defaultScav, "ScavTrap");

	// Test parameterized constructor
	std::cout << "\n--- Parameterized Constructor ---" << std::endl;
	ScavTrap namedScav("Warrior");
	printStatus(namedScav, "ScavTrap");

	// Test copy constructor
	std::cout << "\n--- Copy Constructor ---" << std::endl;
	ScavTrap copyScav(namedScav);
	printStatus(copyScav, "ScavTrap");

	// Test assignment operator
	std::cout << "\n--- Assignment Operator ---" << std::endl;
	ScavTrap assignScav;
	assignScav = namedScav;
	printStatus(assignScav, "ScavTrap");

	printSeparator("ATTRIBUTE VALUES VERIFICATION");

	std::cout << "\n--- ScavTrap Attributes ---" << std::endl;
	ScavTrap testScav("TestBot");
	printStatus(testScav, "ScavTrap");
	std::cout << "Expected: HP=100, EP=50, AD=20" << std::endl;

	printSeparator("INHERITED FUNCTIONS TEST");

	std::cout << "\n--- Testing Inherited takeDamage() ---" << std::endl;
	ScavTrap tankScav("Tank");
	printStatus(tankScav, "ScavTrap");
	tankScav.takeDamage(30);
	printStatus(tankScav, "ScavTrap");

	std::cout << "\n--- Testing Inherited beRepaired() ---" << std::endl;
	tankScav.beRepaired(15);
	printStatus(tankScav, "ScavTrap");

	printSeparator("OVERRIDDEN ATTACK FUNCTION TEST");

	std::cout << "\n--- ClapTrap vs ScavTrap attack messages ---" << std::endl;
	ClapTrap clap("BasicBot");
	ScavTrap scav("EliteBot");

	std::cout << "\nClapTrap attack:" << std::endl;
	clap.attack("Enemy");

	std::cout << "\nScavTrap attack (should be different message):" << std::endl;
	scav.attack("Enemy");

	printSeparator("SPECIAL ABILITY TEST");

	std::cout << "\n--- guardGate() Special Ability ---" << std::endl;
	ScavTrap guardian("Guardian");
	guardian.guardGate();
	guardian.guardGate(); // Test multiple calls

	printSeparator("STRESS TESTS");

	std::cout << "\n--- Energy Depletion Test ---" << std::endl;
	ScavTrap energyTest("Energetic");
	printStatus(energyTest, "ScavTrap");

	// Use up energy points (50 attacks)
	for (int i = 1; i <= 52; i++) {
		std::cout << "Attack " << i << ": ";
		energyTest.attack("Target");
		if (i == 50) {
			std::cout << "\n--- Should have no energy left now ---" << std::endl;
			printStatus(energyTest, "ScavTrap");
		}
	}

	std::cout << "\n--- Damage Test ---" << std::endl;
	ScavTrap damageTest("Tough");
	printStatus(damageTest, "ScavTrap");

	damageTest.takeDamage(50);
	printStatus(damageTest, "ScavTrap");

	damageTest.takeDamage(60); // Should destroy it
	printStatus(damageTest, "ScavTrap");

	damageTest.attack("Ghost"); // Should fail
	damageTest.beRepaired(10); // Should fail
	damageTest.guardGate(); // Should still work

	printSeparator("COMPARISON TEST");

	std::cout << "\n--- ClapTrap vs ScavTrap Side by Side ---" << std::endl;
	ClapTrap basicBot("Basic");
	ScavTrap eliteBot("Elite");

	std::cout << "\nInitial stats:" << std::endl;
	printStatus(basicBot, "ClapTrap");
	printStatus(eliteBot, "ScavTrap");

	std::cout << "\nAfter taking 15 damage:" << std::endl;
	basicBot.takeDamage(15);
	eliteBot.takeDamage(15);
	printStatus(basicBot, "ClapTrap");
	printStatus(eliteBot, "ScavTrap");

	std::cout << "\nAttack comparison:" << std::endl;
	basicBot.attack("Target");
	eliteBot.attack("Target");

	printSeparator("DESTRUCTOR ORDER TEST");
	std::cout << "\nAll objects will be destroyed in reverse order of creation...\n" << std::endl;

	return 0;
}
