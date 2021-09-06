#include "Zombie.hpp"
#include <string>
#include <sstream>

Zombie* zombieHorde( int N, std::string name ) {

	int	i;
    Zombie* Horde;

	i = 0;
	if (N <= 0)
		return (0);
	Horde = new Zombie[N];
	while (i < N)
	{
		std::ostringstream oss;
		oss << name << " " << i;
		Horde[i++].setName(oss.str());
	}
	return(&Horde[0]);
}
