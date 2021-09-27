#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include "Span.hpp"

using std::cout;
using std::endl;
using std::rand;
using std::random_shuffle;

void	subject_test ( void );
void	subject_test_excep_full ( void );
void	subject_test_excep_no_span ( void );
void	test_N ( vector<int> vec, unsigned int N );
void	test_max_min_int ( void ) ;

int main ( void ) {

	//std::srand(unsigned(std::time(NULL)));
	vector<int> vec(500000);
    generate(vec.begin(), vec.end(), rand);
	//generate(begin(vec), end(vec), rand);

	cout << "----- Subject test -----" << endl;
	try {
		subject_test();
	}
	catch (Span::IsFullException &e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (Span::NoSpan &e) {
		cout << "Error: " << e.what() << endl;
	}

	cout << "----- Max/min Integers test -----" << endl;
	try {
		test_max_min_int();
	}
	catch (Span::IsFullException &e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (Span::NoSpan &e) {
		cout << "Error: " << e.what() << endl;
	}
	
	cout << "----- Subject test: Exception Full -----" << endl;
	try {
		subject_test_excep_full();
	}
	catch (Span::IsFullException &e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (Span::NoSpan &e) {
		cout << "Error: " << e.what() << endl;
	}
	
	cout << "----- Subject test: Exception Empty -----" << endl;
	try {
		subject_test_excep_no_span();
	}
	catch (Span::IsFullException &e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (Span::NoSpan &e) {
		cout << "Error: " << e.what() << endl;
	}
	
	cout << "----- 100 test -----" << endl;
	
	//random_shuffle(begin(vec), end(vec));
	random_shuffle(vec.begin(), vec.end());
	try {
		test_N(vec, 100);
	}
	catch (Span::IsFullException &e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (Span::NoSpan &e) {
		cout << "Error: " << e.what() << endl;
	}

	cout << "----- 10000 test -----" << endl;
	
	//random_shuffle(begin(vec), end(vec));
	random_shuffle(vec.begin(), vec.end());
	try {
		test_N(vec, 10000);
	}
	catch (Span::IsFullException &e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (Span::NoSpan &e) {
		cout << "Error: " << e.what() << endl;
	}

	cout << "----- 500000 test -----" << endl;
	
	//random_shuffle(begin(vec), end(vec));
	random_shuffle(vec.begin(), vec.end());
	try {
		test_N(vec, 500000);
	}
	catch (Span::IsFullException &e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (Span::NoSpan &e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}