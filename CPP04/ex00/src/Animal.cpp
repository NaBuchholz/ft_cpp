#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Generic animal sound" << std::endl;
}
