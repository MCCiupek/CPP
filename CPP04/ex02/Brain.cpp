#include <iostream>
#include "Brain.hpp"
#include <cstdlib>

/* CONSTRUCTORS, DESTRUCTORS */

Brain::Brain( void ) {

	std::cout << "Brain Default constructor called" << std::endl;
	return;
}

Brain::Brain( std::string ideas[100] ) {

    this->_ideas = ideas;
	std::cout << "Brain Parametric constructor called" << std::endl;
	return;
}

Brain::Brain( const Brain &Brain ) {

	std::cout << "Brain Copy constructor called" << std::endl;
	*this = Brain;
	return;
}

Brain::~Brain( void ) {

	std::cout << "Brain Destructor called" << std::endl;
	return;
}

/* ASSIGNATION OPERATOR */

Brain & Brain::operator= (const Brain &Brain ) {

	this->setIdeas(Brain.getIdeas());
	std::cout << "Brain Assignation operator called" << std::endl;
	return *this;
}

/* GETTERS, SETTERS */

std::string*	Brain::getIdeas( void ) const {

	return (this->_ideas);
}

void		Brain::setIdeas( std::string ideas[100] ) {

	this->_ideas = ideas;
	return;
}

/* PUBLIC METHODS */

std::string Brain::getIdea(void) const
{
	return(_ideas[rand() % 100]);
}

std::ostream&	operator<<(std::ostream& stream, Brain const& Brain)
{
    std::string* ideas;

    ideas = Brain.getIdeas();
    for (int i = 0; i < 100; i++)
	    stream << ideas[i] << std::endl;
	return (stream);
}
