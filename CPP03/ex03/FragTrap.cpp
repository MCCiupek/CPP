#include <iostream>
#include "FragTrap.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

FragTrap::FragTrap( void ) {

	this->setHitPts (defHitPts);
	this->setEnergyPts (defEnergyPts);
	this->setAttackDamage (defAttackDamage);
	std::cout << "FragTrap Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( std::string name ) {

	this->setName (name);
	this->setHitPts (defHitPts);
	this->setEnergyPts (defEnergyPts);
	this->setAttackDamage (defAttackDamage);
	std::cout << "FragTrap Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( std::string name, int hit_points, int energy_points, int attack_damage ) {

	this->setName (name);
	this->setHitPts (hit_points);
	this->setEnergyPts (energy_points);
	this->setAttackDamage (attack_damage);
	std::cout << "FragTrap Parametric constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( const FragTrap &FragTrap ) {

	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = FragTrap;
	return;
}

FragTrap::~FragTrap( void ) {

	std::cout << "FragTrap Destructor called" << std::endl;
	return;
}

/* GETTERS, SETTERS */

int	FragTrap::getDefHitPts( void ) const {

	return defHitPts;
}

int	FragTrap::getDefEnergyPts( void ) const {

	return defEnergyPts;
}

int	FragTrap::getDefAttackDamage( void ) const {

	return defAttackDamage;
}

/* ASSIGNATION OPERATOR */

FragTrap & FragTrap::operator= (const FragTrap &FragTrap ) {

	this->setName(FragTrap.getName());
	this->setHitPts(FragTrap.getHitPts());
	this->setEnergyPts(FragTrap.getEnergyPts());
	this->setAttackDamage(FragTrap.getAttackDamage());
	std::cout << "FragTrap Assignation operator called" << std::endl;
	return *this;
}

/* PUBLIC METHODS */

void FragTrap::highFivesGuys( void ) {

	std::cout << "FragTrap " << this->getName() 
		<< " wants to high five!" << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, FragTrap const& FragTrap)
{
	stream << "FragTrap " << FragTrap.getName() << " has " 
		<< FragTrap.getHitPts() << " hit points, " 
		<< FragTrap.getEnergyPts() << " energy points and " 
		<< FragTrap.getAttackDamage() << " attack dammage." 
		<< std::endl;
	return (stream);
}
