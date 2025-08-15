#include "../includes/Dog.hpp"

Dog::Dog() : brain(new Brain()) {
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->brain = new Brain(*other.brain); // deep copy
	this->type = other.type;
	std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain); // deep copy
	}
	return *this;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}
