#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
	std::cout << "=== Testing Abstract Animal Class ===" << std::endl;

	// This should NOT compile - AAnimal is abstract
	// AAnimal* animal = new AAnimal(); // Error!

	std::cout << "\n=== Creating animals array ===" << std::endl;
	const AAnimal* animals[4];

	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();

	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	std::cout << "\n=== Making sounds ===" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << animals[i]->getType() << " says: ";
		animals[i]->makeSound();
	}

	std::cout << "\n=== Testing deep copy ===" << std::endl;
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "I love bones!");
	originalDog.getBrain()->setIdea(1, "Squirrel!");

	Dog copyDog(originalDog);
	std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;

	// Modify original
	originalDog.getBrain()->setIdea(0, "I love treats!");
	std::cout << "After modifying original:" << std::endl;
	std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog idea 0: " << copyDog.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n=== Testing assignment operator ===" << std::endl;
	Cat cat1;
	Cat cat2;

	cat1.getBrain()->setIdea(0, "I love fish!");
	cat2 = cat1;

	std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

	cat1.getBrain()->setIdea(0, "I love milk!");
	std::cout << "After modifying cat1:" << std::endl;
	std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n=== Cleaning up ===" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	return 0;
}
