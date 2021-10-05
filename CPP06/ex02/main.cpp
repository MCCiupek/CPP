#include "Base.hpp"
#include <iostream>
#include <stdlib.h>

Base * generate( void ) {

	switch ( rand() % 3 )
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void identify( Base * p ) {

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Type can't be identified" << std::endl;
}

void identify( Base & p ) {

	try { 
		Base & res = dynamic_cast<A&>(p); 
		std::cout << "A" << std::endl;
		(void)res;
		return ;
	}
	catch ( std::exception &e ) { (void)e; }

	try { 
		Base & res = dynamic_cast<B&>(p); 
		std::cout << "B" << std::endl;
		(void)res;
		return ;
	}
	catch ( std::exception &e ) { (void)e; }

	try { 
		Base & res = dynamic_cast<C&>(p); 
		std::cout << "C" << std::endl;
		(void)res;
		return ;
	}
	catch ( std::exception &e ) { (void)e; }

	std::cout << "Type can't be identified" << std::endl;
}

void generate_and_identify( void )
{
	Base * ptr = generate();
	Base & ref = *ptr;

	std::cout << "Pointer: ";
	identify(ptr);

	std::cout << "Reference: ";
	identify(ref);

	delete ptr;
}

void identify_wrong_class( void )
{
	Base * wrongPtr = new D;
	Base & wrongRef = *wrongPtr;

	std::cout << "Wrong Pointer: ";
	identify(wrongPtr);

	std::cout << "Wrong Reference: ";
	identify(wrongRef);

	delete wrongPtr;
}

int main()
{
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++)
		generate_and_identify();
	
	identify_wrong_class();

	return 0;
}