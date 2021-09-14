#include <iostream>
#include "Dog.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

Dog::Dog( void ) : Animal("Dog") {

	this->_brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
	return;
}

Dog::Dog( const Dog &Dog ) {

	//this->_brain = new Brain();
	//*(this->_brain) = *(Dog._brain);
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = Dog;
	return;
}

Dog::~Dog( void ) {

	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
	return;
}

/* ASSIGNATION OPERATOR */

Dog & Dog::operator= (const Dog &Dog ) {

	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &Dog)
	{
		this->_type = Dog.getType();
		this->_brain = new Brain(*Dog._brain);
	}
	return *this;
}

/* PUBLIC METHODS */

void		Dog::makeSound( void ) const {

	std::cout << "Woof Woof" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Dog const& Dog)
{
	(void)Dog;
	stream << "I'm a dog." << std::endl;
	return (stream);
}
