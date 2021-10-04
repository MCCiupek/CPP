#include <iostream>
#include "Dog.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

Dog::Dog( void ) : Animal("Dog") {

	this->_brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
	return;
}

Dog::Dog( const Dog &Dog ) {

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
		delete this->_brain;
		this->_type = Dog.getType();
		this->_brain = new Brain(*Dog._brain);
	}
	return *this;
}

Brain *		Dog::getBrain( void ) const {

	return this->_brain;
}

void 		Dog::setBrain( Brain & brain ) {

	this->_brain = &brain;
}

/* PUBLIC METHODS */

void		Dog::makeSound( void ) const {

	std::cout << "Woof Woof" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Dog const& Dog)
{
	Dog.makeSound();
	stream << "I'm a dog and I'm thinking: " << Dog.getBrain()->getIdea() << std::endl;
	return (stream);
}
