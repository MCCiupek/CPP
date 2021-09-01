#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {

	return;
}

HumanA::~HumanA( void ) {

	return;
}

std::string	HumanA::getName( void ) const {

	return this->_name;
}

void		HumanA::setName( std::string name ) {

	this->_name = name;
}

Weapon&		HumanA::getWeapon( void ) const {

	return this->_weapon;
}

void		HumanA::setWeapon( Weapon& weapon ) {

	this->_weapon = weapon;
}

void		HumanA::attack( void ) const {

	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
