#include "Zombie.hpp"

Zombie::Zombie(const std::string& zombieName)
{
	name = zombieName;
	std::cout << "Zombie " << name << " created!" << std::endl;
};

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed!" << std::endl;
};

void Zombie::announce( void ){
	std::cout << getName() << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() const{
	return name;
};
