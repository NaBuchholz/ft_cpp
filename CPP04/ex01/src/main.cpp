#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << "\n--- Deep Copy Test ---" << std::endl;

	Dog basic;
	{
		Dog tmp = basic; // calls copy constructor (deep copy)
	} // tmp is destroyed, but basic must still have its own Brain

	return 0;
}
