#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <string>

class PhoneBook {
	private:
		Contact contacts[8];
		int contactCount;
		int currentIndex;

		std::string truncateString(const std::string& str, size_t width) const;
		std::string formatField(const std::string& field, size_t width) const;
		void displayContactList() const;
		void displayContact(int index) const;
		std::string getInput(const std::string& prompt) const;

	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContact() const;
		void run();
};

#endif
