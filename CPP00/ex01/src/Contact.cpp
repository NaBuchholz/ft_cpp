#include "Contact.hpp"
#include <iostream>

Contact::Contact() {

};

Contact::~Contact() {

};

void Contact::setFirstName(const std::string& name) {
    firstName = name;
};

std::string Contact::getFirstName() const {
    return firstName;
};

void Contact::setLastName(const std::string& name) {
    lastName = name;
};

std::string Contact::getLastName() const {
    return lastName;
};

void Contact::setNickname(const std::string& nick) {
    nickname = nick;
};

std::string Contact::getNickname() const {
    return nickname;
};

void Contact::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
};

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
};


void Contact::setDarkestSecret(const std::string& darkSecret) {
    darkestSecret = darkSecret;
};

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
};

void Contact::displayContact() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
    return (firstName.empty() || lastName.empty() || 
            nickname.empty() || phoneNumber.empty() || 
            darkestSecret.empty());
}