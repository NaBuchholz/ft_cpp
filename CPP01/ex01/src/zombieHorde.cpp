#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	Zombie* horde = new Zombie[N];
	int i;
	
	i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		std::cout << "Zombie " << name << " is the index " << i++ << std::endl;
	}
	return (horde);
};