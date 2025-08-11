#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() {
	contactCount = 0;
	currentIndex = 0;
}

PhoneBook::~PhoneBook() {
}

std::string PhoneBook::getInput(const std::string& prompt) const {
	std::string input;

	do {
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl;
			return "";
		}
		if (input.empty()) {
			std::cout << "Field cannot be empty. Please try again." << std::endl;
		}
	} while (input.empty());

	return input;
}

void PhoneBook::addContact() {
	std::cout << "Adding new contact..." << std::endl;

	std::string firstName = getInput("First name");
	if (firstName.empty()) return;

	std::string lastName = getInput("Last name");
	if (lastName.empty()) return;

	std::string nickname = getInput("Nickname");
	if (nickname.empty()) return;

	std::string phoneNumber = getInput("Phone number");
	if (phoneNumber.empty()) return;

	std::string darkestSecret = getInput("Darkest secret");
	if (darkestSecret.empty()) return;

	contacts[currentIndex].setFirstName(firstName);
	contacts[currentIndex].setLastName(lastName);
	contacts[currentIndex].setNickname(nickname);
	contacts[currentIndex].setPhoneNumber(phoneNumber);
	contacts[currentIndex].setDarkestSecret(darkestSecret);

	currentIndex = (currentIndex + 1) % 8;
	if (contactCount < 8) {
		contactCount++;
	}

	std::cout << "Contact added successfully!" << std::endl;
}

std::string PhoneBook::truncateString(const std::string& str, size_t width) const {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	}
	return str;
}

std::string PhoneBook::formatField(const std::string& field, size_t width) const {
	std::string truncated = truncateString(field, width);
	std::ostringstream oss;
	oss << std::setw(width) << std::right << truncated;
	return oss.str();
}

void PhoneBook::displayContactList() const {
	std::cout << "|" << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;

	for (int i = 0; i < contactCount; i++) {
		std::cout << "|" << std::setw(10) << std::right << i << "|";
		std::cout << formatField(contacts[i].getFirstName(), 10) << "|";
		std::cout << formatField(contacts[i].getLastName(), 10) << "|";
		std::cout << formatField(contacts[i].getNickname(), 10) << "|" << std::endl;
	}
}

void PhoneBook::displayContact(int index) const {
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact() const {
	if (contactCount == 0) {
		std::cout << "No contacts available." << std::endl;
		return;
	}

	displayContactList();

	std::string input;
	std::cout << "Enter index to display: ";
	if (!std::getline(std::cin, input)) {
		std::cout << std::endl;
		return;
	}

	std::istringstream iss(input);
	int index;
	if (!(iss >> index) || !iss.eof()) {
		std::cout << "Invalid input. Please enter a valid index." << std::endl;
		return;
	}

	if (index < 0 || index >= contactCount) {
		std::cout << "Index out of range." << std::endl;
		return;
	}

	displayContact(index);
}

void PhoneBook::run() {
	std::string command;

	std::cout << "Welcome to your awesome PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, command)) {
			std::cout << std::endl;
			break;
		}

		if (command == "ADD") {
			addContact();
		} else if (command == "SEARCH") {
			searchContact();
		} else if (command == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break;
		} else {
			std::cout << "Invalid command. Available commands: ADD, SEARCH, EXIT" << std::endl;
		}
	}
}
