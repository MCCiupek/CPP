#include <iostream>
#include "FragTrap.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

FragTrap::FragTrap( void ) : ClapTrap() {

	this->setHitPts (100);
	this->setEnergyPts (50);
	this->setAttackDamage (20);
	std::cout << "FragTrap Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name, 100, 50, 20) {

	std::cout << "FragTrap Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( std::string name, int hit_points, int energy_points, int attack_damage ) : ClapTrap(name, hit_points, energy_points, attack_damage) {

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

void FragTrap::guardGate( void ) {

	std::cout << "FragTrap " << this->getName() 
		<< " has enterred in Gate keeper mode " << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, FragTrap const& FragTrap)
{
	stream << "FragTrap " << FragTrap.getName() << " has " 
		<< FragTrap.getHitPts() << " hit points, " 
		<< FragTrap.getEnergyPts() << " energy points and " 
		<< FragTrap.getAttackDamage() << " attack dammage.";
	return (stream);
}
