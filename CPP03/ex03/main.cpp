#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	std::cout << std::endl;

	std::cout << "-------- FRAGTRAP -----------" << std::endl;
	FragTrap c("C");
	std::cout << c;
	c.attack("something");
	c.takeDamage(2);
	c.beRepaired(5);
	std::cout << c;
	c.highFivesGuys();

	std::cout << std::endl;

	std::cout << "-------- DIAMONDTRAP -----------" << std::endl;
	DiamondTrap d("D");
	std::cout << d;
	d.attack("something");
	d.takeDamage(2);
	d.beRepaired(5);
	std::cout << d;
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();

	std::cout << std::endl;

	std::cout << "-------- DESTRUCTORS -----------" << std::endl;

	return 0;
}