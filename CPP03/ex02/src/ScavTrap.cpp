#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

// Overridden attack function
void ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name
				  << " can't attack because it has no hit points left!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name
				  << " can't attack because it has no energy points left!" << std::endl;
		return;
	}

	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

// Special ability
void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
