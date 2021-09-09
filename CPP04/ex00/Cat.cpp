#include <iostream>
#include "Cat.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

Cat::Cat( void ) : Animal("Cat") {

	std::cout << "Cat Default constructor called" << std::endl;
	return;
}

Cat::Cat( const Cat &Cat ) {

	std::cout << "Cat Copy constructor called" << std::endl;
	*this = Cat;
	return;
}

Cat::~Cat( void ) {

	std::cout << "Cat Destructor called" << std::endl;
	return;
}

/* ASSIGNATION OPERATOR */

Cat & Cat::operator= (const Cat &Cat ) {

	this->_type = Cat.getType();
	std::cout << "Cat Assignation operator called" << std::endl;
	return *this;
}

/* PUBLIC METHODS */

void		Cat::makeSound( void ) const {

	std::cout << "Meeeeoooow" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Cat const& Cat)
{
	(void)Cat;
	stream << "I'm a cat." << std::endl;
	return (stream);
}
