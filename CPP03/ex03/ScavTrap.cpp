#include <iostream>
#include "ScavTrap.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

ScavTrap::ScavTrap( void ) {

	this->setHitPts (defHitPts);
	this->setEnergyPts (defEnergyPts);
	this->setAttackDamage (defAttackDamage);
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name ) {

	this->setName (name);
	this->setHitPts (defHitPts);
	this->setEnergyPts (defEnergyPts);
	this->setAttackDamage (defAttackDamage);
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name, int hit_points, int energy_points, int attack_damage ) {

	this->setName (name);
	this->setHitPts (hit_points);
	this->setEnergyPts (energy_points);
	this->setAttackDamage (attack_damage);
	std::cout << "ScavTrap Parametric constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( const ScavTrap &ScavTrap ) {

	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = ScavTrap;
	return;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "ScavTrap Destructor called" << std::endl;
	return;
}

/* GETTERS, SETTERS */

int	ScavTrap::getDefHitPts( void ) const {

	return defHitPts;
}

int	ScavTrap::getDefEnergyPts( void ) const {

	return defEnergyPts;
}

int	ScavTrap::getDefAttackDamage( void ) const {

	return defAttackDamage;
}

/* ASSIGNATION OPERATOR */

ScavTrap & ScavTrap::operator= (const ScavTrap &ScavTrap ) {

	this->setName(ScavTrap.getName());
	this->setHitPts(ScavTrap.getHitPts());
	this->setEnergyPts(ScavTrap.getEnergyPts());
	this->setAttackDamage(ScavTrap.getAttackDamage());
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	return *this;
}

/* PUBLIC METHODS */

void ScavTrap::guardGate( void ) {

	std::cout << "ScavTrap " << this->getName() 
		<< " has enterred in Gate keeper mode " << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, ScavTrap const& ScavTrap)
{
	stream << "ScavTrap " << ScavTrap.getName() << " has " 
		<< ScavTrap.getHitPts() << " hit points, " 
		<< ScavTrap.getEnergyPts() << " energy points and " 
		<< ScavTrap.getAttackDamage() << " attack dammage."
		<< std::endl;
	return (stream);
}
