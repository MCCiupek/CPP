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
		delete this->_brain;
		this->_type = Cat.getType();
		this->_brain = new Brain(*Cat._brain);
	}
	return *this;
}

Brain *		Cat::getBrain( void ) const {

	return this->_brain;
}

void 		Cat::setBrain( Brain & brain ) {

	this->_brain = &brain;
}

/* PUBLIC METHODS */

void		Cat::makeSound( void ) const {

	std::cout << "Meeeeoooow" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Cat const& Cat)
{
	Cat.makeSound();
	stream << "I'm a cat and I'm thinking: " << Cat.getBrain()->getIdea() << std::endl;
	return (stream);
}
