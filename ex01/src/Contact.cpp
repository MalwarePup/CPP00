#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

std::string Contact::promptForNonEmptyInput(const std::string & prompt) const
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
	return input;
}

std::string Contact::truncate(const std::string & str, int width) const
{
	if (str.length() > static_cast<size_t>(width))
	{
		return str.substr(0, width - 1) + '.';
	}
	return str;
}

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
}

void Contact::setContact()
{
	_firstName = promptForNonEmptyInput("First Name: ");
	_lastName = promptForNonEmptyInput("Last Name: ");
	_nickname = promptForNonEmptyInput("Nickname: ");
	_phoneNumber = promptForNonEmptyInput("Phone Number: ");
	_darkestSecret = promptForNonEmptyInput("Darkest Secret: ");

	std::cout << "\033[32m\nContact added successfully!\n\033[0m" << std::endl;
}

void Contact::displayShort(int index) const
{
	std::cout << std::setw(10) << index << "|"
		<< std::setw(10) << truncate(_firstName) << "|"
		<< std::setw(10) << truncate(_lastName) << "|"
		<< std::setw(10) << truncate(_nickname) << std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << "\n" << std::endl;
}
