#include <iostream>
#include "ScavTrap.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

ScavTrap::ScavTrap( void ) : ClapTrap() {

	this->setHitPts (100);
	this->setEnergyPts (50);
	this->setAttackDamage (20);
	std::cout << "ScavTrap Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20) {

	std::cout << "ScavTrap Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name, int hit_points, int energy_points, int attack_damage ) : ClapTrap(name, hit_points, energy_points, attack_damage) {

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
		<< ScavTrap.getAttackDamage() << " attack dammage.";
	return (stream);
}
