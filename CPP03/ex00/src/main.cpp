#include "ClapTrap.hpp"

void printSeparator(const std::string& testName) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "         " << testName << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void printStatus(const ClapTrap& clap) {
	std::cout << "Status - HP: " << clap.getHitPoints()
			  << " | EP: " << clap.getEnergyPoints()
			  << " | AD: " << clap.getAttackDamage() << std::endl;
}

int main(void) {
	printSeparator("CONSTRUCTOR TESTS");

	std::cout << "\n--- Default Constructor ---" << std::endl;
	ClapTrap defaultClap;
	printStatus(defaultClap);

	std::cout << "\n--- Parameterized Constructor ---" << std::endl;
	ClapTrap namedClap("Roboto");
	printStatus(namedClap);

	std::cout << "\n--- Copy Constructor ---" << std::endl;
	ClapTrap copyClap(namedClap);
	printStatus(copyClap);

	std::cout << "\n--- Assignment Operator ---" << std::endl;
	ClapTrap assignClap;
	assignClap = namedClap;
	printStatus(assignClap);

	printSeparator("BASIC FUNCTIONALITY TESTS");

	std::cout << "\n--- Normal Attack ---" << std::endl;
	ClapTrap warrior("Warrior");
	printStatus(warrior);
	warrior.attack("Goblin");
	printStatus(warrior);

	std::cout << "\n--- Repair Test ---" << std::endl;
	warrior.takeDamage(5);
	printStatus(warrior);
	warrior.beRepaired(3);
	printStatus(warrior);

	printSeparator("EDGE CASE TESTS");

	std::cout << "\n--- No Energy Points Test ---" << std::endl;
	ClapTrap tiredClap("Tired");

	for (int i = 0; i < 10; i++) {
		tiredClap.attack("Target");
	}
	printStatus(tiredClap);

	tiredClap.attack("NewTarget");
	tiredClap.beRepaired(5);

	std::cout << "\n--- No Hit Points Test ---" << std::endl;
	ClapTrap dyingClap("Dying");
	printStatus(dyingClap);

	// Take fatal damage
	dyingClap.takeDamage(15);
	printStatus(dyingClap);

	// Try actions with no hit points
	dyingClap.attack("Ghost");
	dyingClap.beRepaired(10);
	dyingClap.takeDamage(5); // More damage when already dead

	std::cout << "\n--- Large Damage Test ---" << std::endl;
	ClapTrap tankClap("Tank");
	printStatus(tankClap);
	tankClap.takeDamage(100);
	printStatus(tankClap);

	std::cout << "\n--- Multiple Repairs Test ---" << std::endl;
	ClapTrap healerClap("Healer");
	healerClap.takeDamage(8);
	printStatus(healerClap);

	for (int i = 0; i < 3; i++) {
		healerClap.beRepaired(2);
		printStatus(healerClap);
	}

	printSeparator("DESTRUCTOR TESTS");
	std::cout << "\nDestructors will be called when objects go out of scope...\n" << std::endl;

	return 0;
}
