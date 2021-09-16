#include <iostream>
#include "ClapTrap.hpp"

int main(void) {

	std::cout << "-------- CLAPTRAP -----------" << std::endl;
	ClapTrap a("A");
	std::cout << a;
	a.attack("something");
	a.takeDamage(2);
	a.beRepaired(5);
	std::cout << a;

	/*ClapTrap b1("b");
	ClapTrap c("c");
	ClapTrap b(b1);
	ClapTrap c1("c1");

	c = c1;

	a.attack(b.getName());
	b.attack(c.getName());
	c.attack(a.getName());

	b.takeDamage(a.getAttackDamage());
	c.takeDamage(b.getAttackDamage());
	a.takeDamage(c.getAttackDamage());

	a.beRepaired(2);
	b.beRepaired(3);
	c.beRepaired(5);*/

	return 0;
}