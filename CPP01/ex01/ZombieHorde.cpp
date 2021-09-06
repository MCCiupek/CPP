#include "Zombie.hpp"
#include <string>
#include <sstream>

Zombie* zombieHorde( int N, std::string name ) {

	int	i;
    Zombie* Horde = new Zombie[N];

	i = 0;
	while (i < N)
	{
		std::ostringstream oss;
		oss << name << " " << i;
		Horde[i++].setName(oss.str());
	}
	return(&Horde[0]);
}
