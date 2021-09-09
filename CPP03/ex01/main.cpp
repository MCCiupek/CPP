#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	ClapTrap a("a");
	ClapTrap b1("b");
	ClapTrap c("c");
	ClapTrap b(b1);
	ClapTrap c1("c1");

	c = c1;

	ScavTrap blair;
	ScavTrap serena("Serena");
	ScavTrap gossip_girl;
	ScavTrap xoxo("Dan", 100, 100, 100);

	gossip_girl = xoxo;

	a.attack("b");
	b.attack("c");
	c.attack("a");

	b.takeDamage(a.getAttackDamage());
	c.takeDamage(b.getAttackDamage());
	a.takeDamage(c.getAttackDamage());

	a.beRepaired(2);
	b.beRepaired(3);
	c.beRepaired(5);
	
	blair.setName("Blair");
	blair.guardGate();
	serena.attack(blair.getName());
	blair.takeDamage(serena.getAttackDamage());
	serena.guardGate();
	gossip_girl.guardGate();

	return 0;
}