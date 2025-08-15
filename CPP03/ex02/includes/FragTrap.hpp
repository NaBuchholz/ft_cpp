#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// Orthodox Canonical Form
	FragTrap(void);                                     // Default constructor
	FragTrap(const std::string& name);                 // Parameterized constructor
	FragTrap(const FragTrap& other);                   // Copy constructor
	FragTrap& operator=(const FragTrap& other);        // Assignment operator
	~FragTrap(void);                                   // Destructor

	// Special ability
	void highFivesGuys(void);
};

#endif
