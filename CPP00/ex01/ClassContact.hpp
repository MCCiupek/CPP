#ifndef __CLASS_CONTACT_H__
# define __CLASS_CONTACT_H__

#include <iostream>
#include <string>
#include <iomanip>

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Contact {

public:

	Contact( void );
	~Contact( void );

	void	DisplayShortView(void);
	void	DisplayFullView(void);

	int			index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif /* __CLASS_CONTACT_H__ */
