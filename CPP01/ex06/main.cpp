#include "Karen.hpp"

std::string to_lower(std::string str){

	size_t	i = 0;

	while (i++ < str.length()){
		str[i - 1] = std::tolower(str[i - 1]);
	}
	return str;
}

std::string to_upper(std::string str){

	size_t	i = 0;

	while (i++ < str.length()){
		str[i - 1] = std::toupper(str[i - 1]);
	}
	return str;
}

int getInstruction(std::string input) {
	if( input == "DEBUG" ) return DEBUG;
	if( input == "INFO" ) return INFO;
	if( input == "WARNING" ) return WARNING;
	if( input == "ERROR" ) return ERROR;
	return -1;
 }

int exec( int n ) {

	Karen	karen;
	std::string	complaints_level[NUM_OPT] = {
		"debug",
		"info",
		"warning",
		"error"
	};

	while (n < NUM_OPT) {
		std::cout << "[ " << to_upper(complaints_level[n]) << " ]" << std::endl;
		karen.complain(complaints_level[n++]);
		if (n < NUM_OPT)
			std::cout << std::endl;
	}
	return 0;
}

int main( int ac, char *av[] ) {

	if (ac != 2) {
		std::cout << "Error: Missing log level" << std::endl;
		return (1);
	}
	switch (getInstruction(av[1])) {
		case DEBUG :
			exec(0);
			break ;
		case INFO :
			exec(1);
			break ;
		case WARNING :
			exec(2);
			break ;
		case ERROR :
			exec(3);
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
