#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
				<< " can't attack because it has no hit points left!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name
				<< " can't attack because it has no energy points left!" << std::endl;
		return;
	}

	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
				<< " is already destroyed and can't take more damage!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;

	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
	} else {
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " now has "
				<< this->_hitPoints << " hit points left." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
				<< " can't repair itself because it has no hit points left!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name
				<< " can't repair itself because it has no energy points left!" << std::endl;
		return;
	}

	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself, recovering "
			<< amount << " hit points! Current HP: " << this->_hitPoints << std::endl;
}

const std::string& ClapTrap::getName(void) const {
	return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}
