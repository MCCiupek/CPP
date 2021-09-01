#include "ClassContact.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

std::string truncate(std::string str, size_t width, bool show_trunc=true)
{

	if (str.length() > width)
	{
		if (show_trunc)
			return str.substr(0, width - 1) + ".";
		else
			return str.substr(0, width);
	}
	return str;

}

void	Contact::DisplayShortView(void) {

	std::cout << "|" << std::setw(10) << this->index << "|";
	std::cout << std::setw(10) << truncate(this->first_name, 10) << "|";
	std::cout << std::setw(10) << truncate(this->last_name, 10) << "|";
	std::cout << std::setw(10) << truncate(this->nickname, 10) << "|";
	std::cout << std::endl;

}

void	Contact::DisplayFullView(void) {

	std::cout << "Index: " << this->index << std::endl;
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;

}