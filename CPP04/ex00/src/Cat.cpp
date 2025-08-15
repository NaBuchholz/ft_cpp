#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
	std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow meow!" << std::endl;
}
