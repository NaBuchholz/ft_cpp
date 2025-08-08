#include "Zombie.hpp"

int main()
{
	std::cout << "========= Before randomChump (Stack)========" << std::endl;
	Zombie zombieStack("Stack Zombie");
	zombieStack.announce();
	std::cout << "====== After randomChump ==========" << std::endl;

	std::cout << "====== Before newZombie (Heap) ==========" << std::endl;
	Zombie* zombieHeap = new Zombie("Heap Zombie");
	zombieHeap->announce();
	std::cout << zombieHeap->getName() << ": deleting from heap..." << std::endl;
	delete zombieHeap;
	std::cout << "====== After newZombie (Heap) ==========" << std::endl;
	return (0);
}
