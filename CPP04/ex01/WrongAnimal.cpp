#include <iostream>
#include "WrongAnimal.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

WrongAnimal::WrongAnimal( void ) {

	std::cout << "WrongAnimal Default constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type) {

	std::cout << "WrongAnimal Parametric constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal( const WrongAnimal &WrongAnimal ) {

	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = WrongAnimal;
	return;
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout << "WrongAnimal Destructor called" << std::endl;
	return;
}

/* ASSIGNATION OPERATOR */

WrongAnimal & WrongAnimal::operator= (const WrongAnimal &WrongAnimal ) {

	this->setType(WrongAnimal.getType());
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	return *this;
}

/* GETTERS, SETTERS */

std::string	WrongAnimal::getType( void ) const {

	return (this->_type);
}

void		WrongAnimal::setType( std::string const type ) {

	this->_type = type;
	return;
}

/* PUBLIC METHODS */

void		WrongAnimal::makeSound( void ) const {

	std::cout << "* random animal noise *" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, WrongAnimal const& WrongAnimal)
{
	stream << "WrongAnimal: " << WrongAnimal.getType() << std::endl;
	return (stream);
}