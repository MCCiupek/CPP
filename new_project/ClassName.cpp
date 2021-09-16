#include "ClassName.hpp"
#include <iostream>

/* CONSTRUCTORS, DESTRUCTORS */

ClassName::ClassName( void ) {

	return;
}

ClassName::ClassName( std::string name ) : _name(name) {

	return;
}

ClassName::ClassName( const ClassName &Copy ) {

	*this = Copy;
	return;
}

ClassName::~ClassName( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

ClassName & ClassName::operator= (const ClassName &Copy ) {

	if (this != &Copy)
	{
		/* code */
	}
	return *this;
}

/* GETTERS, SETTERS */

std::string	const & ClassName::getName( void ) const {

	return (this->_name);
}

void    ClassName::setName( std::string name ) {

    this->_name = name;
	return ;
}

/* PUBLIC METHODS */

std::ostream&	operator<<(std::ostream& stream, ClassName const& Copy)
{
	stream << "ClassName: " << Copy.getName() << std::endl;
	return (stream);
}