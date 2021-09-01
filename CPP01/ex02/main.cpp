#include <string>
#include <iostream>

int	main( void ) {

	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "string address: " << &str << std::endl;
	std::cout << "string address using PTR: " << stringPTR << std::endl;
	std::cout << "string address using REF: " << &stringREF << std::endl;

	std::cout << "string: " << str << std::endl;
	std::cout << "string using PTR: " << *stringPTR << std::endl;
	std::cout << "string using REF: " << stringREF << std::endl;

	return 0;

}

