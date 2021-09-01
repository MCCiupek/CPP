#ifndef __CLASS_PHONEBOOK_H__
# define __CLASS_PHONEBOOK_H__

#include "ClassContact.hpp"
#include <iostream>
#include <string>
#include "colors.hpp"

// ************************************************************************** //
//                             PhoneBook Class                                //
// ************************************************************************** //

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	Add(void);
	void	Search(void);

private:

	int		_count;
	Contact	_Contacts[8];

	void	_Display(void);

};

#endif /* __CLASS_PHONEBOOK_H__ */
