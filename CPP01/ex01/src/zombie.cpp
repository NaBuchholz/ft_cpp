#include "Zombie.hpp"

Zombie::Zombie()
{
	std::string name;
};

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed!" << std::endl;
};

std::string Zombie::getName() const{
	return name;
};

void Zombie::setName(const std::string& zombieName){
	name = zombieName;
	std::cout << "Zombie " << name << " created!" << std::endl;
}

void Zombie::announce( void ){
	std::cout << getName() << " : BraiiiiiiinnnzzzZ..." << std::endl;
}