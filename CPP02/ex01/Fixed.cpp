#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {

	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( int const n ) : _value(n << _nbBits) {

	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( float const f ) : _value(roundf(f * (1 << _nbBits))) {

	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const &Number ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = Number;
	return;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed & Fixed::operator= ( Fixed const &Number ) {

	std::cout << "Assignation operator called" << std::endl;
	this->_value = Number._value;
	return *this;
}

int	Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void		Fixed::setRawBits( int const raw ) {

	this->_value = raw;
	return;
}

float 		Fixed::toFloat(void) const {

	return (float)(this->_value) / (1 << _nbBits);
}

int 		Fixed::toInt(void) const {

	return (int)(this->_value >> _nbBits);
}

std::ostream &	operator<<( std::ostream & o, Fixed const & Number ){

	o << Number.toFloat();
	return o;
}
