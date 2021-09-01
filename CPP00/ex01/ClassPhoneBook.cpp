#include "ClassPhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void	PhoneBook::Add(void) {

	Contact	newContact;

	if (this->_count > 7)
	{
		std::cout << RED << "Your phone book is full. So many friends!!" << WHITE << std::endl;
		return;
	}
	newContact.index = this->_count;
	std::cout << "First name: ";
	std::cin >> newContact.first_name;

	std::cout << "Last name: ";
	std::cin >> newContact.last_name;

	std::cout << "Nickname: ";
	std::cin >> newContact.nickname;

	std::cout << "Phone number: ";
	std::cin >> newContact.phone_number;

	std::cout << "Darkest secret: ";
	std::cin >> newContact.darkest_secret;

	this->_Contacts[this->_count++] = newContact;
	return;

}

void	PhoneBook::_Display(void) {

	int	i;
	
	i = 0;
	std::cout << "|     index|";
	std::cout << "first name|";
	std::cout << " last_name|";
	std::cout << "  nickname|";
	std::cout << std::endl;
	while (i < this->_count)
		this->_Contacts[i++].DisplayShortView();

}

void	PhoneBook::Search(void) {

	int	index;

	if (!this->_count)
	{
		std::cout << "Your phone book is empty! Add your BFF's number!" << std::endl;
		return;
	}
	this->_Display();
	std::cout << "Enter an index: ";
	std::cin >> index;
	while (std::cin.fail() || index < 0 || index > this->_count)
	{
		std::cout << RED << "Index must be an integer between a 0 and " << this->_count - 1 << WHITE << std::endl;
		std::cout << "Enter an index: ";
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> index;
	}
	this->_Contacts[index].DisplayFullView();
	return;

}
