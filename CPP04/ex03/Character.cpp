#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

/* CONSTRUCTORS, DESTRUCTORS */

Character::Character( void ) {

	for (int i = 0; i < 4; i++) { this->_inventory[i] = 0; }
	return;
}

Character::Character( std::string name ) : _name(name) {

	for (int i = 0; i < 4; i++) { this->_inventory[i] = 0; }
	return;
}

Character::Character( const Character &Copy ) {

	*this = Copy;
	return;
}

Character::~Character( void ) {

	for (int i = 0; i < 4; i++) { delete this->_inventory[i]; }
	for (int i = 0; i < 4; i++) { this->_inventory[i] = 0; }
	return;
}

/* ASSIGNATION OPERATOR */

Character & Character::operator= (const Character &Copy ) {

	if (this != &Copy)
	{
		this->_name = Copy.getName();
		for (int i = 0; i < 4; i++) {
			if (!_inventory[i]) {
				_inventory[i] = Copy._inventory[i]->clone();
			}
		}
	}
	return *this;
}

/* GETTERS, SETTERS */

std::string	const & Character::getName( void ) const {

	return (this->_name);
}

/* PUBLIC METHODS */

void Character::equip( AMateria* m ) {

	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
	return ;
}

void Character::unequip( int idx ) {

	if (_inventory[idx])
		_inventory[idx] = NULL;
	return ;
}

void		Character::use( int idx, ICharacter& target ) {

	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Character const& Copy)
{
	stream << "Character: " << Copy.getName() << std::endl;
	return (stream);
}