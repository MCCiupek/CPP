#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

	std::cout << std::endl << "-- CLAP TRAP CONSTRUCTORS --" << std::endl;

	ClapTrap a("C-TP1");
	ClapTrap b1("C-TP2");
	ClapTrap c("C-TP3.0");
	ClapTrap b(b1);
	ClapTrap c1("C-TP3.1");

	c = c1;

	std::cout << std::endl << "-- SCAV TRAP CONSTRUCTORS --" << std::endl;

	ScavTrap blair;
	ScavTrap serena("S-TP2");
	ScavTrap gossip_girl;
	ScavTrap xoxo("S-TP3", 100, 100, 100);

	gossip_girl = xoxo;

	std::cout << std::endl << "-- FRAG TRAP CONSTRUCTORS --" << std::endl;

	FragTrap ftp1;
	FragTrap ftp2("F-TP2");
	FragTrap ftp3;
	FragTrap ftp4("F-TP4", 100, 100, 100);

	ftp3 = ftp4;

	std::cout << std::endl << "-- DIAMOND TRAP CONSTRUCTORS --" << std::endl;

	DiamondTrap	ruby;
	DiamondTrap	green_rock;
	DiamondTrap	saphire("D-TP2");

	green_rock = saphire;

	std::cout << std::endl << "-- TESTS --" << std::endl;

	std::cout << std::endl;

	std::cout << blair;
	std::cout << ftp1;

	std::cout << std::endl;

	a.attack(b.getName());
	b.attack(c.getName());
	c.attack(a.getName());

	b.takeDamage(a.getAttackDamage());
	c.takeDamage(b.getAttackDamage());
	a.takeDamage(c.getAttackDamage());

	a.beRepaired(2);
	b.beRepaired(3);
	c.beRepaired(5);
	
	blair.setName("S-TP1");
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

	saphire.highFivesGuys();
	ruby.setName("D-TP1");
	ruby.guardGate();
	ruby.whoAmI();
	std::cout << saphire;
	green_rock.whoAmI();

	std::cout << std::endl << "-- DESCONSTRUCTORS --" << std::endl;

	return 0;
}