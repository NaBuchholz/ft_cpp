#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;
public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;
    void displayContactDetails(int index) const;
};

#endif