#include "Zombie.hpp"

int main( void ) {

	int		i;
	int		N = 10;
	Zombie*	Horde = zombieHorde(N, "toto");
	Zombie*	Head = Horde;

	i = 0;
	while (i++ < N)
		Horde++->announce();
	if (Head)
		delete [] Head;
	return 0;
}
