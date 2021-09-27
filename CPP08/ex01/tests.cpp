#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
#include "Span.hpp"

using std::cout;
using std::endl;
using std::rand;

void	subject_test ( void ) {

	Span sp = Span(5);

    sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	cout << "sp: [ " << sp << "]" << endl;
	cout << "Shortest Span: " << sp.shortestSpan() << endl;
	cout << "Longest Span: " << sp.longestSpan() << endl;

}

void	test_max_min_int ( void ) {

	Span sp = Span(5);

    sp.addNumber(-INT_MIN);
	sp.addNumber(3);
	sp.addNumber(-INT_MIN);
	sp.addNumber(0);
	sp.addNumber(INT_MAX);

	cout << "sp: [ " << sp << "]" << endl;
	cout << "Shortest Span: " << sp.shortestSpan() << endl;
	cout << "Longest Span: " << sp.longestSpan() << endl;

}

void	subject_test_excep_full ( void ) {

	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(11);

	cout << "sp: [ " << sp << "]" << endl;
	cout << "Shortest Span: " << sp.shortestSpan() << endl;
	cout << "Longest Span: " << sp.longestSpan() << endl;

}

void	subject_test_excep_no_span ( void ) {

	Span sp = Span(5);

	cout << sp.shortestSpan() << endl;

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	cout << "sp: [ " << sp << "]" << endl;
	cout << "Shortest Span: " << sp.shortestSpan() << endl;
	cout << "Longest Span: " << sp.longestSpan() << endl;

}

void	test_N ( vector<int> vec, unsigned int N ) {

	Span sp = Span(N);

	sp.addNumber(vec.begin(), vec.size() >= N ? vec.begin() + N - sp.getVec().size() : vec.end());

	cout << "sp: [ " << sp << "] with nb elem = " << sp.getVec().size() << "/" << sp.getN() << endl;
	cout << "Shortest Span: " << sp.shortestSpan() << endl;
	cout << "Longest Span: " << sp.longestSpan() << endl;

}

