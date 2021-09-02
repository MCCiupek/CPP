#include "Karen.hpp"

Karen::Karen( void ) {

	this->f[DEBUG] = &Karen::debug;
	this->f[INFO] = &Karen::info;
	this->f[WARNING] = &Karen::warning;
	this->f[ERROR] = &Karen::error;
	return;
}

Karen::~Karen( void ) {

	return;
}

void	debug( void ) {

	std::cout << "I love to get extra bacon for my \
		7XL-double-cheese-triple-pickle-special-ketchup burger. \
		I just love it!" << std::endl;
	return;
}

void	info( void ) {

	std::cout << "I cannot believe adding extra \
		bacon cost more money. You don’t put enough! \
		If you did I would not have to ask for it!" << std::endl;
	return;
}

void	warning( void ) {

	std::cout << "I think I deserve to have some extra bacon for free. \
		I’ve been coming here for years and you just started \
		working here last month." << std::endl;
	return;
}

void	error( void ) {

	std::cout << "This is unacceptable, \
		I want to speak to the manager now." << std::endl;
	return;
}

void	Karen::complain( std::string level ) {

	std::string	complaints_level[NUM_OPT] = { "debug", "info", "warning", "error" };

	/*fptr	functions[NUM_OPT] = {
		{ "debug", &Karen::debug },
		{ "info", &Karen::info },
		{ "warning", &Karen::warning },
		{ "error", &Karen::error }
	};*/
	for (int i = 0; i < NUM_OPT; ++i) {
		if (!complaints_level[i].compare(level))
			//(this->*f[i])();
			std::cout << i << std::endl;
			//(this->*(functions[i].f()))();
	}
	return;
}
