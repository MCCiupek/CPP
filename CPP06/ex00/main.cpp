#include <iostream>

using std::cout;
using std::endl;

int main(int ac, char *av[])
{
	std::string s;
	double      n;

	if (ac != 2 || av[1][0] == '\0') {
		std::cout << "Expected format: ./convert <str>" << std::endl;
		return (1);
	}
	else
	{
		s = av[1];
		if (!std::isdigit(s[0]) && s.length() == 1) {
			n = static_cast<int>(s[0]);
		} else {
			n = std::atof(av[1]);
		}
	}
	return 0;
}