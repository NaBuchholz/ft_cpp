#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "=== Test constructors and destructors ===" << std::endl;
	{
		// Creating a FragTrap inside a scope to check constructor order
		// ClapTrap constructor must be called first, then FragTrap
		// When leaving the scope, FragTrap destructor must be called first, then ClapTrap
		FragTrap frag("Fraggy");
	}
	std::cout << std::endl;

	std::cout << "=== Test initial attributes and basic actions ===" << std::endl;
	FragTrap f1("Terminator");
	f1.attack("test-target");   // consumes energy and shows attack message
	f1.takeDamage(20);          // reduces hit points by 20
	f1.beRepaired(10);          // recovers 10 hit points, costs 1 energy point
	std::cout << std::endl;

	std::cout << "=== Test energy exhaustion ===" << std::endl;
	// Try to attack until the energy points are depleted
	for (int i = 0; i < 101; i++) {
		f1.attack("dummy");
	}
	std::cout << std::endl;

	std::cout << "=== Test special ability highFivesGuys() ===" << std::endl;
	f1.highFivesGuys(); // should print a positive high-five request
	std::cout << std::endl;

	std::cout << "=== Test with multiple FragTraps ===" << std::endl;
	FragTrap f2("Alpha");
	FragTrap f3("Beta");

	f2.attack("Beta");   // Alpha attacks Beta
	f3.takeDamage(30);   // Beta takes 30 damage
	f3.highFivesGuys();  // Beta requests high-fives
	std::cout << std::endl;

	return 0;
}
