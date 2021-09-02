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

int check_nb_args( int ac ) {

	if (ac != 4) {
		std::cout << "Error: arguments. Try ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	return 0;
}

std::string check_str( std::string str ) {

	if (str.empty()) {
		std::cout << "Error: wrong number of arguments. s1 and s2 should not be empty strings." << std::endl;
		str.clear();
		return str;
	}
	return str;
}
/*
std::ifstream check_infile( std::string filename ) {

	std::ifstream	ifs(filename);

	if (!ifs.is_open()) {
		std::cout << "Error: could not open input file." << std::endl;
		return ifs;
	}
	return ifs;
}*/

int main( int ac, char *av[] )
{
	std::string word;
	char		ws = 0;

	if (check_nb_args(ac))
		return 1;

	std::string s1 = check_str(av[2]);
	std::string s2 = check_str(av[3]);
	if (s1.empty() || s2.empty())
		return 1;

	//std::ifstream	ifs = check_infile(av[1]);
	std::ifstream	ifs(av[1]);

	if (!ifs.is_open()) {
		std::cout << "Error: could not open input file." << std::endl;
		return 1;
	}

	if (!ifs.is_open())
		return 1;

	std::ofstream	ofs(to_upper(av[1]) + ".replace");

	if (!ofs.is_open()) {
		std::cout << "Error: could not open output file." << std::endl;
		ifs.close();
		return 1;
	}

	while (ifs >> word) {
		if (ws) {
			if (!(ws + word).compare(s1))
				ofs << s2;
			else
				ofs << ws + word;
		}
		else
		{
			if (!word.compare(s1))
				ofs << s2;
			else
				ofs << word;
		}
		ifs.get(ws);
		while (std::isspace(ws)) {
			ofs << ws;
			if (ifs.eof())
				break;
			ifs.get(ws);
		}
		if (ifs.eof())
			break;
	}
	ifs.close();
	ofs.close();
	return 0;
}
