#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	FragTrap ftp1;
	FragTrap ftp2("F-TP2");
	FragTrap ftp3;
	FragTrap ftp4("F-TP4", 100, 100, 100);

	ftp3 = ftp4;

	a.attack(b.getName());
	b.attack(c.getName());
	c.attack(a.getName());

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

	ftp1.setName("F-TP1");
	ftp2.highFivesGuys();
	ftp2.attack(ftp1.getName());
	ftp1.takeDamage(ftp2.getAttackDamage());
	ftp3.highFivesGuys();

	std::cout << gossip_girl;

	return 0;
}