#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* Constructors */

Fixed::Fixed( void ) : _value(0) {

	return;
}

Fixed::Fixed( int const n ) : _value(n << _nbBits) {

	return;
}

Fixed::Fixed( float const f ) : _value(roundf(f * (1 << _nbBits))) {

	return;
}

Fixed::Fixed( Fixed const &Number ) {

	*this = Number;
	return;
}

/* Destructor */

Fixed::~Fixed( void ) {

	return;
}

/* Assignation Operator Overload */

Fixed & 	Fixed::operator= ( Fixed const &Number ) {

	this->_value = Number._value;
	return *this;
}

/* Comparison Operators Overloads */

bool	 	Fixed::operator> ( Fixed const &Number ) const {

	return this->_value > Number._value;
}

bool	 	Fixed::operator< ( Fixed const &Number ) const {

	return this->_value < Number._value;
}

bool	 	Fixed::operator>= ( Fixed const &Number ) const {

	return this->_value >= Number._value;
}

bool	 	Fixed::operator<= ( Fixed const &Number ) const {

	return this->_value <= Number._value;
}

bool	 	Fixed::operator== ( Fixed const &Number ) const {

	return this->_value == Number._value;
}

/* Arithmetic Operators Overloads */

Fixed	 	Fixed::operator+ ( Fixed const &Number ) const {

	return Fixed(this->toFloat() + Number.toFloat());
}

Fixed	 	Fixed::operator- ( Fixed const &Number ) const {

	return Fixed(this->toFloat() - Number.toFloat());
}

Fixed	 	Fixed::operator* ( Fixed const &Number ) const {

	return Fixed(this->toFloat() * Number.toFloat());
}

Fixed	 	Fixed::operator/ ( Fixed const &Number ) const {

	return Fixed(this->toFloat() / Number.toFloat());
}

/* Increment/Decrement Operators Overloads */

Fixed &	 	Fixed::operator++ ( void ) {

	this->_value++;
	return *this;
}

Fixed	 	Fixed::operator++ ( int ) {

	Fixed ret(*this);
	operator++();
	return ret;
}

Fixed &	 	Fixed::operator-- ( void ) {

	this->_value--;
	return *this;
}

Fixed	 	Fixed::operator--( int ) {

	Fixed ret(*this);
	operator--();
	return ret;
}

/* Min / Max */

Fixed &	Fixed::min( Fixed &a, Fixed &b) {
	
	if (a <= b)
		return a;
	return b;
}

Fixed &	Fixed::max( Fixed &a, Fixed &b) {
	
	if (a >= b)
		return a;
	return b;
}

const Fixed &	Fixed::min( Fixed const &a, Fixed const &b) {
	
	if (a <= b)
		return a;
	return b;
}

const Fixed &	Fixed::max( Fixed const &a, Fixed const &b) {
	
	if (a >= b)
		return a;
	return b;
}

/* Methods */

int			Fixed::getRawBits( void ) const {

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

/* << Operator Overload */

std::ostream &	operator<<( std::ostream & o, Fixed const & Number ){

	o << Number.toFloat();
	return o;
}
