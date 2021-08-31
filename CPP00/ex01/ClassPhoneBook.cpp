#include "ClassPhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void	PhoneBook::Add(void) {
	Contact	newContact;

	if (this->count > 7)
	{
		std::cout << RED << "Your phone book is full. So many friends!!" << WHITE << std::endl;
		return;
	}
	newContact.index = this->count;
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

	this->Contacts[this->count++] = newContact;
	return;
}

void	PhoneBook::Display(void) {
	int	i;
	
	i = 0;
	std::cout << "|     index|";
	std::cout << "first name|";
	std::cout << " last_name|";
	std::cout << "  nickname|";
	std::cout << std::endl;
	while (i < this->count)
		this->Contacts[i++].DisplayShortView();
}

void	PhoneBook::Search(void) {
	int	index;

	if (!this->count)
	{
		std::cout << "Your phone book is empty! Add your BFF's number!" << std::endl;
		return;
	}
	this->Display();
	std::cout << "Enter an index: ";
	std::cin >> index;
	while (std::cin.fail() || index < 0 || index > this->count)
	{
		std::cout << RED << "Index must be an integer between a 0 and " << this->count - 1 << WHITE << std::endl;
		std::cout << "Enter an index: ";
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> index;
	}
	this->Contacts[index].DisplayFullView();
	return;
}
