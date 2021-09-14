#include <iostream>
#include "AMateria.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

AMateria::AMateria( void ) {

    return;
}

AMateria::AMateria( std::string const & type ) : _type(type) {

	return;
}

AMateria::AMateria( const AMateria &Copy ) {

	*this = Copy;
	return;
}

AMateria::~AMateria( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

AMateria & AMateria::operator= (const AMateria &Copy ) {

	this->setType(Copy.getType());
	return *this;
}

/* GETTERS, SETTERS */

std::string	const & AMateria::getType( void ) const {

	return (this->_type);
}

void		AMateria::setType( std::string const type ) {

	this->_type = type;
	return;
}

/* PUBLIC METHODS */

void		AMateria::use( ICharacter& target ) {

    std::cout << "* use Materia on " << target.getName() << " *" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, AMateria const& AMateria)
{
	stream << "AMateria: " << AMateria.getType() << std::endl;
	return (stream);
}