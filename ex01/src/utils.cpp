#include <cstdlib>
#include <iostream>
#include "Phonebook.hpp"

void printMenu()
{
	std::cout << "Please select an option from the following list:" << std::endl;
	std::cout << "\033[1mADD\033[0m: Add a new contact to the phonebook" << std::endl;
	std::cout << "\033[1mSEARCH\033[0m: Search for a contact in the phonebook" << std::endl;
	std::cout << "\033[1mEXIT\033[0m: Exit the phonebook" << std::endl;
}

void processUserInput(const std::string& userInput, PhoneBook& phoneBook)
{
	std::string options[] = {"ADD", "SEARCH", "EXIT"};

	for (int i = 0; i < 3; i++)
	{
		if (userInput == options[i])
		{
			switch (i)
			{
			case 0:
				std::cout << "\033[1mADD\033[0m selected" << std::endl;
				phoneBook.addContact();
				break;
			case 1:
				std::cout << "\033[1mSEARCH\033[0m selected" << std::endl;
				phoneBook.searchContact();
				break;
			case 2:
				std::cout << "\033[1mEXIT\033[0m selected" << std::endl;
				exit(EXIT_SUCCESS);
				break;
			}
			return;
		}
	}
	std::cerr << "\033[1;31m\nError: Invalid input. Please try again.\033[0m" << std::endl;
}

std::string getUserInput()
{
	std::string userInput;

	std::cout << "\nPlease enter your selection: ";
	std::getline(std::cin, userInput);
	if (std::cin.eof())
	{
		std::cout << "\nEOF detected. Exiting program." << std::endl;
		exit(EXIT_SUCCESS);
	}
	if (userInput.empty())
	{
		std::cerr << "\033[1;31m\nError: Input cannot be empty. Please try again.\033[0m" << std::endl;
		return getUserInput();
	}
	return userInput;
}
