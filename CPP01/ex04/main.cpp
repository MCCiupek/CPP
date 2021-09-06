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

void	print_whitespaces(std::ifstream& ifs, std::ofstream& ofs) {
	
	char		ws = 0;

	ifs.get(ws);
	while (std::isspace(ws)) {
		if (ifs.eof())
			break;
		ofs << ws;
		ifs.get(ws);
	}
	ifs.putback(ws);
}

void	sed(std::ifstream& ifs, std::ofstream& ofs, std::string s1, std::string s2) {

	std::string word;

	print_whitespaces(ifs, ofs);
	while (ifs >> word) {
		if (!word.compare(s1))
			ofs << s2;
		else
			ofs << word;
		print_whitespaces(ifs, ofs);
		if (ifs.eof())
			break;
	}
}

int main( int ac, char *av[] )
{
	if (check_nb_args(ac))
		return 1;

	std::string s1 = check_str(av[2]);
	std::string s2 = check_str(av[3]);
	if (s1.empty() || s2.empty())
		return 1;

	std::ifstream	ifs(av[1]);

	if (!ifs.is_open()) {
		std::cout << "Error: could not open input file." << std::endl;
		return 1;
	}

	std::ofstream	ofs(to_upper(av[1]) + ".replace");

	if (!ofs.is_open()) {
		std::cout << "Error: could not open output file." << std::endl;
		ifs.close();
		return 1;
	}

	sed(ifs, ofs, s1, s2);

	ifs.close();
	ofs.close();
	return 0;
}
