#include <iostream>
#include "WrongCat.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {

	std::cout << "WrongCat Default constructor called" << std::endl;
	return;
}

WrongCat::WrongCat( const WrongCat &WrongCat ) {

	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = WrongCat;
	return;
}

WrongCat::~WrongCat( void ) {

	std::cout << "WrongCat Destructor called" << std::endl;
	return;
}

/* ASSIGNATION OPERATOR */

WrongCat & WrongCat::operator= (const WrongCat &WrongCat ) {

	this->_type = WrongCat.getType();
	std::cout << "WrongCat Assignation operator called" << std::endl;
	return *this;
}

/* PUBLIC METHODS */

void		WrongCat::makeSound( void ) const {

	std::cout << "Meeeeoooow" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, WrongCat const& WrongCat)
{
	(void)WrongCat;
	stream << "I'm a WrongCat." << std::endl;
	return (stream);
}
