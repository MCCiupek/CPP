#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {

	return;
}

HumanB::~HumanB( void ) {

	return;
}

std::string	HumanB::getName( void ) const {

	return this->_name;
}

void		HumanB::setName( std::string name ) {

	this->_name = name;
}

Weapon*		HumanB::getWeapon( void ) const {

	return this->_weapon;
}

void		HumanB::setWeapon( Weapon& weapon ) {

	this->_weapon = &weapon;
}

void		HumanB::attack( void ) const {

	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
