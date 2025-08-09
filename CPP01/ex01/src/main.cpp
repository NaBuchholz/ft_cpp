#include "Zombie.hpp"

int main()
{
	Zombie* horde;
	int i;

	i = 0;
	std::cout << "========= Creating Horde manually ===========" << std::endl;
	horde = zombieHorde(5, "enzo");
	std::cout << "========= Announcing Horde manually ===========" << std::endl;
	while(i < 5)
	{	
		horde[i].announce();
		std::cout << horde[i].getName() << " is index " << i << std::endl;
		i++;
	}
	std::cout << "========= Deleting Horde manually ===========" << std::endl;
	delete[] horde;
	return (0);
}
