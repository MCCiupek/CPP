#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {

	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( const Fixed &Number ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = Number;
	return;
}

Fixed & Fixed::operator= (const Fixed &Number ) {

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
