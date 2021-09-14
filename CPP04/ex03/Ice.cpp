#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

Ice::Ice( void ) : AMateria("ice") {

	return;
}

Ice::Ice( const Ice &Ice ) : AMateria(Ice) {

	return;
}

Ice::~Ice( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

Ice & Ice::operator= (const Ice &Ice ) {

	if (this != &Ice)
		this->_type = Ice.getType();
	return *this;
}

/* PUBLIC METHODS */

AMateria*   Ice::clone() const {

	return new Ice(*this);
}

void		Ice::use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Ice const& Ice)
{
	stream << "Type: " << Ice.getType() << std::endl;
	return (stream);
}
