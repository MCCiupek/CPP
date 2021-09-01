#include "Zombie.hpp"

void randomChump( std::string name ) {

    Zombie* myZombie = newZombie(name);

	myZombie->announce();
	delete myZombie;
	return;
}
