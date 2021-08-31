#include <iostream>

int main(int argc, char *argv[])
{
	int     i;
	int     j;
	char    ch;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i++])
		{
			j = 0;
			while (argv[i - 1][j])
			{
				ch = toupper(argv[i - 1][j++]);
				std::cout << ch;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}