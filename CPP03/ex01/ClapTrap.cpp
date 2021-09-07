#include <iostream>
#include "ClapTrap.hpp"

/* CONSTRUCTORS, DESTRUCTORS */

ClapTrap::ClapTrap( void ) : _hit_points(10), _energy_points(10), _attack_damage(0) {

	std::cout << "Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string name, int hit_points, int energy_points, int attack_damage ) : _name(name), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage) {

	std::cout << "Parametric constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( const ClapTrap &ClapTrap ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = ClapTrap;
	return;
}

ClapTrap::~ClapTrap( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

/* ASSIGNATION OPERATOR */

ClapTrap & ClapTrap::operator= (const ClapTrap &ClapTrap ) {

	this->setName(ClapTrap.getName());
	this->setHitPts(ClapTrap.getHitPts());
	this->setEnergyPts(ClapTrap.getEnergyPts());
	this->setAttackDamage(ClapTrap.getAttackDamage());
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

/* GETTERS, SETTERS */

std::string	ClapTrap::getName( void ) const {

	return (this->_name);
}

void		ClapTrap::setName( std::string const name ) {

	this->_name = name;
	return;
}

int	ClapTrap::getHitPts( void ) const {

	return (this->_hit_points);
}

void		ClapTrap::setHitPts( int const hit_points ) {

	this->_hit_points = hit_points;
	return;
}

int	ClapTrap::getEnergyPts( void ) const {

	return (this->_energy_points);
}

void		ClapTrap::setEnergyPts( int const energy_points ) {

	this->_energy_points = energy_points;
	return;
}

int	ClapTrap::getAttackDamage( void ) const {

	return (this->_attack_damage);
}

void		ClapTrap::setAttackDamage( int const attack_damage ) {

	this->_attack_damage = attack_damage;
	return;
}

/* PUBLIC METHODS */

void ClapTrap::attack(std::string const & target) {

	this->_hit_points--;
	std::cout << "ClapTrap " << this->getName() 
		<< " attack " << target 
		<< ", causing " << this->getAttackDamage() << " points of damage!" 
		<< std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {

	this->_energy_points -= amount;
	std::cout << "ClapTrap " << this->getName() 
		<< " has taken " << amount << " points of damage! It has "
		<< this->getEnergyPts() << " energy points now." 
		<< std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {

	this->_energy_points += amount;
	std::cout << "ClapTrap " << this->getName() 
		<< " has been repaired by " << amount << " points! It has "
		<< this->getEnergyPts() << " energy points now." 
		<< std::endl;
	return ;
}
