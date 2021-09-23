#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

using std::vector;
using std::deque;
using std::cout;
using std::endl;

int test_vector ( void ) {

	vector<int>				vec(5, 5);
	vector<int>::iterator	it;
	int						to_find;

	try {
		to_find = 5;
		it = easyfind(vec, to_find);
		cout << "Element " << to_find << " found in vector" << endl;
	}
	catch ( ElemNotFound &e ) {
		cout << "Error: " << to_find << ": " << e.what() << endl;
	}

	try {
		to_find = 6;
		it = easyfind(vec, to_find);
		cout << "Element " << to_find << " found in vector" << endl;
	}
	catch ( ElemNotFound &e ) {
		cout << "Error: " << to_find << ": " << e.what() << endl;
	}

	return 0;
}

int test_deque ( void ) {

	deque<int>				deq;
	deque<int>::iterator	it;
	int						to_find;

	for (int i = 0; i < 5; i++)
		deq.push_back(i);

	try {
		to_find = 2;
		it = easyfind(deq, to_find);
		cout << "Element " << to_find << " found in deque" << endl;
	}
	catch ( ElemNotFound &e ) {
		cout << "Error: " << to_find << ": " << e.what() << endl;
	}

	try {
		to_find = 6;
		it = easyfind(deq, to_find);
		cout << "Element " << to_find << " found in deque" << endl;
	}
	catch ( ElemNotFound &e ) {
		cout << "Error: " << to_find << ": " << e.what() << endl;
	}

	return 0;
}

int main ( void ) {

	cout << "------ Test vector ------" << endl;
	test_vector();

	cout << endl;

	cout << "------ Test deque ------" << endl;
	test_deque();

	return 0;
}