#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	this->brain = new Brain(*other.brain); // deep copy
	this->type = other.type;
	std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain); // deep copy
	}
	return *this;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}
