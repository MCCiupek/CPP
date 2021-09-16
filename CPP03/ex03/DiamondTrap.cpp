#include <iostream>
#include "DiamondTrap.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

DiamondTrap::DiamondTrap( void ) : ClapTrap("unnamed_clap_name", 100, 50, 30), FragTrap("unnamed"), ScavTrap("unnamed"), _name("unnamed") {

	std::cout << "DiamondTrap Default constructor called" << std::endl;
	return;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name", 100, 50, 30), FragTrap(name), ScavTrap(name), _name(name) {

	std::cout << "DiamondTrap Default constructor called" << std::endl;
	return;
}

DiamondTrap::DiamondTrap( std::string name, int hit_points, int energy_points, int attack_damage ) {

	this->setName(name);
	this->setHitPts (hit_points);
	this->setEnergyPts (energy_points);
	this->setAttackDamage (attack_damage);
	std::cout << "DiamondTrap Parametric constructor called" << std::endl;
	return;
}

DiamondTrap::DiamondTrap( const DiamondTrap &DiamondTrap ) {

	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = DiamondTrap;
	return;
}

DiamondTrap::~DiamondTrap( void ) {

	std::cout << "DiamondTrap Destructor called" << std::endl;
	return;
}

/* GETTERS, SETTERS */

std::string	DiamondTrap::getName( void ) const {

	return (this->_name);
}

void		DiamondTrap::setName( std::string const name ) {

	this->_name = name;
	this->setCPName(name);
	return;
}

std::string	DiamondTrap::getCPName( void ) const {

	return ClapTrap::getName();
}

void		DiamondTrap::setCPName( std::string const name ) {

	ClapTrap::setName(name + "_clap_name");
	return;
}

/* ASSIGNATION OPERATOR */

DiamondTrap & DiamondTrap::operator= (const DiamondTrap &DiamondTrap ) {

	this->setName(DiamondTrap.getName());
	this->setHitPts(DiamondTrap.getHitPts());
	this->setEnergyPts(DiamondTrap.getEnergyPts());
	this->setAttackDamage(DiamondTrap.getAttackDamage());
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	return *this;
}

/* PUBLIC METHODS */

void 		DiamondTrap::whoAmI() {
	
	std::cout << "I am DiamondTrap " << this->getName() 
		<< " (" << this->getCPName() << ")" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, DiamondTrap const& DiamondTrap)
{
	stream << "DiamondTrap " << DiamondTrap.getName() 
		<< " (" << DiamondTrap.getCPName() << ")"
		<< " has " 
		<< DiamondTrap.getHitPts() << " hit points, " 
		<< DiamondTrap.getEnergyPts() << " energy points and " 
		<< DiamondTrap.getAttackDamage() << " attack dammage."
		<< std::endl;
	return (stream);
}
