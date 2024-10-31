#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

	std::string promptForNonEmptyInput(const std::string& prompt) const;
	std::string truncate(const std::string &str) const;

public:
	Contact();
	~Contact() {};

	void setContact();

	void displayShort(int index) const;
	void displayFull() const;
};

#endif /* CONTACT_HPP */
