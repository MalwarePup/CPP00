#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

int PhoneBook::promptForIndexInput(const std::string &prompt) const
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting program." << std::endl;
			exit(EXIT_SUCCESS);
		}
		if (!input.empty())
		{
			break;
		}
		else
		{
			std::cerr << "\033[1;31m\nError: Input cannot be empty. Please try again.\033[0m" << std::endl;
		}
	}
	int index;
	std::stringstream ss(input);
	ss >> index;
	return index;
}

PhoneBook::PhoneBook() : _contactCount(0), _currentIndex(0)
{
}

void PhoneBook::addContact()
{
	Contact contact;
	contact.setContact();

	std::cout << "Adding contact at index: " << _currentIndex << std::endl;
	_contacts[_currentIndex] = contact;
	_currentIndex = (_currentIndex + 1) % MAX_CONTACTS;
	if (_contactCount < MAX_CONTACTS)
	{
		_contactCount++;
	}
	std::cout << "Contact added. Total contacts: " << _contactCount << "\n" << std::endl;
}

void PhoneBook::searchContact()
{
	if (this->_contactCount == 0)
	{
		std::cerr << "\033[1;31m\nError: No contacts available. Please add a contact first.\033[0m\n" << std::endl;
		return;
	}
	std::cout << "\n" << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_contactCount; i++)
	{
		_contacts[i].displayShort(i);
	}
	while (true)
	{
		int index = promptForIndexInput("\nEnter the index of the contact to view details: ");
		std::cout << std::endl;
		if (index >= 0 && index < this->_contactCount)
		{
			_contacts[index].displayFull();
			return;
		}
		else
		{
			std::cerr << "\033[1;31mError: Invalid index. Please try again.\033[0m\n" << std::endl;
			continue;
		}
	}
}
