#include <string>
#include <iostream>
#include <fstream>

std::string to_upper(std::string str){

	size_t	i = 0;

	while (i++ < str.length()){
		str[i - 1] = std::toupper(str[i - 1]);
	}
	return str;
}

int main( int ac, char *av[] )
{
	if (ac != 4) {
		std::cout << "Error: arguments. Try ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string s1 = av[2];
	std::string s2 = av[3];;

	if (!s1.compare("") || !s2.compare("")) {
		std::cout << "Error: arguments. s1 and s2 should not be empty strings." << std::endl;
		return 1;
	}

	std::string word;
	std::ifstream	ifs(av[1]);
	std::ofstream	ofs(to_upper(av[1]) + ".replace");

	while (ifs >> word) {
		if (!word.compare(s1))
			ofs << s2 << " ";
		else
			ofs << word << " ";
	}
	ifs.close();
	ofs.close();
	return 0;
}
