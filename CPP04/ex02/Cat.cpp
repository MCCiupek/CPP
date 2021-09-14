#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

Cat::Cat( void ) : Animal("Cat") {

	this->_brain = new Brain;
	std::cout << "Cat Default constructor called" << std::endl;
	return;
}

Cat::Cat( const Cat &Cat ) {

	//this->_brain = new Brain(*Cat._brain);
	//this->_type = Cat.getType();
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = Cat;
	return;
}

Cat::~Cat( void ) {

	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
	return;
}

/* ASSIGNATION OPERATOR */

Cat & Cat::operator= (const Cat &Cat ) {

	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &Cat)
	{
		this->_type = Cat.getType();
		this->_brain = new Brain(*Cat._brain);
	}
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
