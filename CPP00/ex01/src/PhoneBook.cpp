#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(){

};

PhoneBook::~PhoneBook(){

};

PhoneBook::PhoneBook() {
    currentIndex = 0;
    totalContacts = 0;
};

void PhoneBook::addContact() {
    std::string input;
    Contact newContact;

    std::cout << "Enter first name: " << std::endl;
    std::getline(std::cin,input);
    if (input.empty()) {
        std::cout << "Field cannot be empty !" << std::endl;
        return ;
    }
    newContact.setFirstName(input);
    input.clear();
    
};