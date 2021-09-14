#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

Cure::Cure( void ) : AMateria("cure") {

	return;
}

Cure::Cure( const Cure &Cure ) : AMateria(Cure) {

	return;
}

Cure::~Cure( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

Cure & Cure::operator= (const Cure &Cure ) {

	if (this != &Cure)
		this->_type = Cure.getType();
	return *this;
}

/* PUBLIC METHODS */

AMateria*   Cure::clone() const {

	return new Cure(*this);
}

void		Cure::use( ICharacter& target ) {

	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Cure const& Cure)
{
	stream << "Type: " << Cure.getType() << std::endl;
	return (stream);
}
