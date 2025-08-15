#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	// Orthodox Canonical Form
	ScavTrap(void);                                     // Default constructor
	ScavTrap(const std::string& name);                 // Parameterized constructor
	ScavTrap(const ScavTrap& other);                   // Copy constructor
	ScavTrap& operator=(const ScavTrap& other);        // Assignment operator
	~ScavTrap(void);                                   // Destructor

	// Overridden member function
	void attack(const std::string& target);

	// Special ability
	void guardGate(void);
};

#endif
