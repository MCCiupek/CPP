#include <iostream>
#include "Animal.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

Animal::Animal( void ) {

	std::cout << "Animal Default constructor called" << std::endl;
	return;
}

Animal::Animal( std::string type ) : _type(type) {

	std::cout << "Animal Parametric constructor called" << std::endl;
	return;
}

Animal::Animal( const Animal &Animal ) {

	std::cout << "Animal Copy constructor called" << std::endl;
	*this = Animal;
	return;
}

Animal::~Animal( void ) {

	std::cout << "Animal Destructor called" << std::endl;
	return;
}

/* ASSIGNATION OPERATOR */

Animal & Animal::operator= (const Animal &Animal ) {

	this->setType(Animal.getType());
	std::cout << "Animal Assignation operator called" << std::endl;
	return *this;
}

/* GETTERS, SETTERS */

std::string	Animal::getType( void ) const {

	return (this->_type);
}

void		Animal::setType( std::string const type ) {

	this->_type = type;
	return;
}

/* PUBLIC METHODS */

void		Animal::makeSound( void ) const {

	std::cout << "* random animal noise *" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Animal const& Animal)
{
	stream << "Animal: " << Animal.getType() << std::endl;
	return (stream);
}