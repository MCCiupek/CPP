#include <iostream>
#include "Fixed.hpp"

int Fixed::_nbBits = NB_BITS;

Fixed::Fixed( void ) : _value(0) {

	int	i;

	this->_fixed = new int[_nbBits];
	this->_fixed = {0};
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( int const n ) : _value(n) {

	int	i = 0;

	this->_fixed = new int[_nbBits];
	this->_fixed = {0};
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( int const f ) {

	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const &Number ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = Number;
	return;
}

Fixed & Fixed::operator= ( Fixed const &Number ) {

	std::cout << "Assignation operator called" << std::endl;
	this->_value = Number.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
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

	return this->_value;
}

int 		Fixed::toInt(void) const {

	return this->_value;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & Number ){

	o << Number.getRawBits() << std::endl;
	return o;
}
