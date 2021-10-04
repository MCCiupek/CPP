#include <iostream>
#include "Brain.hpp"
#include <cstdlib>
#include <fstream>

/* CONSTRUCTORS, DESTRUCTORS */

Brain::Brain( void ) {

	std::cout << "Brain Default constructor called" << std::endl;
	setIdeas();
	return;
}

Brain::Brain( std::string ideas[100] ) {

    setIdeas(ideas);
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

	if (this != &Brain) {
		setIdeas(Brain.getIdeas());
		std::cout << "Brain Assignation operator called" << std::endl;
	}
	return *this;
}

/* GETTERS, SETTERS */

std::string const *	Brain::getIdeas( void ) const {

	return (&this->_ideas[0]);
}

void		Brain::setIdeas( void ) {

	std::string idea;
	std::ifstream input;
    input.open("ideas.txt");

	int i = 0;
	while (std::getline(input, idea)) {
		_ideas[i++] = idea;
	}
	input.close();
	return;
}

void		Brain::setIdeas( std::string const ideas[100] ) {

	for (int i = 0; i < 100; i++) {
		_ideas[i] = ideas[i];
	}
	return;
}

/* PUBLIC METHODS */

std::string  Brain::getIdea(void) const
{
	return(_ideas[std::rand() % 100]);
}

std::ostream&	operator<<(std::ostream& stream, Brain const& Brain)
{
	stream << Brain.getIdea() << std::endl;
	return stream;
}
