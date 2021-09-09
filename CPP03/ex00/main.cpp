#include <iostream>
#include "ClapTrap.hpp"

int main(void) {

	ClapTrap a("a");
	ClapTrap b1("b");
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
	c.beRepaired(5);

	return 0;
}