#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	ScavTrap blair;
	ScavTrap serena("Serena");

	blair.setName("Blair");
	blair.guardGate();
	serena.attack(blair.getName());
	blair.takeDamage(serena.getAttackDamage());
	serena.guardGate();

	return 0;
}