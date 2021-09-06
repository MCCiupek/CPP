#include "Zombie.hpp"

int main( void ) {

	int		i;
	int		N = 4;
	Zombie*	Horde = zombieHorde(N, "toto");

	//N = 4;
	//Horde = zombieHorde(N, "toto");
	i = 0;
	while (i++ < N)
		Horde++->announce();
	delete [] Horde;
	//i = 0;
	//while (i++ < N)
	//	delete [] Horde++;
	return 0;
}
