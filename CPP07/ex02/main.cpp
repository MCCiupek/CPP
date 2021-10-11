#include <iostream>
#include "Array.hpp"
#include "Human.hpp"

using std::string;
using std::cout;
using std::endl;


int testIntegersArray( void ) {

	Array<int> intArr;
	Array<int> intnArr(5);
	Array<int> intnArr2;
	
	for (unsigned int i = 0; i < intnArr.size(); i++)
		intnArr.setArray(i, i);
	intnArr2 = intnArr;
	intnArr.setArray(0, -1);

	cout << intArr << endl;
	cout << intnArr << endl;
	cout << intnArr2 << endl;

	try {
		cout << intnArr2[12] << endl;
	}
	catch (Array<int>::OutOfLimits &e) {
		cout << "Error: index out of array limit" << endl;
	}

	return 0;
}

int testHumansArray( void ) {

	Array<Human>	Band;
	Array<Human>	Beatles(4);
	
	Beatles.setArray(0, Human("stuart"));
	Beatles.setArray(1, Human("john"));
	Beatles.setArray(2, Human("ringo"));
	Beatles.setArray(3, Human("george"));
	Band = Beatles;
	Beatles.setArray(0, Human("paul"));

	for (unsigned int i = 0; i < Band.size(); i++)
		cout << Band[i].getName() << endl;
	cout << endl;

	for (unsigned int i = 0; i < Band.size(); i++)
		cout << Beatles[i].getName() << endl;
	cout << endl;

	try {
		cout << Beatles[5].getName() << endl;
	}
	catch (Array<Human>::OutOfLimits &e) {
		cout << "Error: index out of array limit" << endl;
	}

	return 0;
}

#define MAX_VAL 750
int main( int, char** )
{
	cout << "------ Test 0: Subject ------" << endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	cout << endl;
	
	cout << "------ Test 1: Integers ------" << endl;
	testIntegersArray();
	cout << endl;

	cout << "------ Test 2: Humans ------" << endl;
	testHumansArray();
	cout << endl;

    return 0;
}
