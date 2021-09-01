#include "Zombie.hpp"

int main( void ) {

	int		i;
	int		N;
	Zombie*	myZombie;

	N = 4;
	myZombie = zombieHorde(N, "toto");
	i = 0;
	while (i++ < N)
		myZombie++->announce();
	delete [] myZombie;
	return 0;
}
