#include "ClassPhoneBook.hpp"
#include "colors.hpp"

int main()
{
	std::string cmd;
	PhoneBook	MyPhoneBook;

	while (cmd.compare("EXIT"))
	{
		std::cout << CYAN << "Enter your command (ADD, SEARCH or EXIT)" << WHITE << std::endl << "> ";
		std::cin >> cmd;
		if (!cmd.compare("ADD"))
			MyPhoneBook.Add();
		else if (!cmd.compare("SEARCH"))
			MyPhoneBook.Search();
		else if (cmd.compare("EXIT") && cmd.compare("ADD") && cmd.compare("SEARCH"))
			std::cout << RED << "Could not understand your command. Please try again." << WHITE << std::endl;
	}
	std::cout << PURPLE << "Hope to see u soon!" << WHITE << std::endl;
	return 0;
}
