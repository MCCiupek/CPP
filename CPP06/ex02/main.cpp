#include "Base.hpp"
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

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
        cout << "A" << endl;
    else if (dynamic_cast<B*>(p))
        cout << "B" << endl;
    else if (dynamic_cast<C*>(p))
        cout << "C" << endl;
}

void identify( Base & p ) {

    identify(&p);
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

int main()
{
    for (int i = 0; i < 10; i++)
        generate_and_identify();
    return 0;
}