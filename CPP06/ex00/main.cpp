#include <iostream>
#include "Convert.hpp"

using std::cout;
using std::endl;

int main(int ac, char *av[])
{
	if (ac != 2 || av[1][0] == '\0') {
		cout << "Expected format: ./convert <str>" << endl;
		return (1);
	}
	else
	{
		Convert	convert(av[1]);
		cout << convert;
	}
	return 0;
}