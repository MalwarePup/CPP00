#include <iostream>
#include "Phonebook.hpp"

void printMenu();
void processUserInput(const std::string& userInput, PhoneBook& phoneBook);
std::string getUserInput();

int main()
{
	PhoneBook phoneBook;
	std::string userInput;
	bool firstIteration = true;

	while (true)
	{
		if (firstIteration)
		{
			std::cout << "\033[1;36mWelcome to the phonebook!\n\033[0m" << std::endl;
			firstIteration = false;
		}
		printMenu();
		userInput = getUserInput();
		processUserInput(userInput, phoneBook);
	}
	return 0;
}
