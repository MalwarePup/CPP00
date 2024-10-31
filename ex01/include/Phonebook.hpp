#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
private:
	Contact _contacts[MAX_CONTACTS];
	int _contactCount;
	int _currentIndex;

	int promptForIndexInput(const std::string &prompt) const;

public:
	PhoneBook();
	~PhoneBook() {};

	void addContact();
	void searchContact();
};

#endif /* PHONEBOOK_HPP */
