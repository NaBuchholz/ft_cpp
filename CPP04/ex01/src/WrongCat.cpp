#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow!" << std::endl;
}
