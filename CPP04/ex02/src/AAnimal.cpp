#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	*this = other;
	std::cout << "AAnimal copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destroyed" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}
