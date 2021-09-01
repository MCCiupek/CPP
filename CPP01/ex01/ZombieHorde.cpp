#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	int	i;
    Zombie* myZombieHorde = new Zombie[N];

	i = 0;
	while (i < N)
		myZombieHorde[i++].setName(name);
	return(&myZombieHorde[0]);
}
