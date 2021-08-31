#ifndef CLASS_PHONEBOOK
# define CLASS_PHONEBOOK

#include "ClassContact.hpp"
#include <iostream>
#include <string>
#include "colors.h"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	Add(void);
	void	Display(void);
	void	Search(void);

	Contact	Contacts[8];

private:
	int		count;
};

#endif
