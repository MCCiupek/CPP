#ifndef CLASS_CONTACT
# define CLASS_CONTACT

#include <iostream>
#include <string>
#include <iomanip>

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

#endif
