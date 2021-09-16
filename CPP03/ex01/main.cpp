#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	std::cout << "-------- CLAPTRAP -----------" << std::endl;
	ClapTrap a("A");
	std::cout << a;
	a.attack("something");
	a.takeDamage(2);
	a.beRepaired(5);
	std::cout << a;

	std::cout << std::endl;

	std::cout << "-------- SCAVTRAP -----------" << std::endl;
	ScavTrap b("B");
	std::cout << b;
	b.attack("something");
	b.takeDamage(2);
	b.beRepaired(5);
	std::cout << b;
	b.guardGate();

	return 0;
}