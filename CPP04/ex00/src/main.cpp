#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	// Testing polymorphism with virtual functions
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	dog->makeSound(); // should output Woof
	cat->makeSound(); // should output Meow

	delete dog;
	delete cat;

	std::cout << "\n--- WrongAnimal Tests ---" << std::endl;

	const WrongAnimal* wrong = new WrongCat();
	wrong->makeSound(); // Will call WrongAnimal's version, not WrongCat's
	delete wrong;

	return 0;
}
