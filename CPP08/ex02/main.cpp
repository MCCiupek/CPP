#include "MutantStack.hpp"
# include <algorithm>
# include <stack>
# include <list>
# include <deque>
# include <iostream>

using std::stack;
using std::deque;
using std::list;
using std::cout;
using std::endl;

int test_with_a_stack()
{
	MutantStack<int> mstack;

	mstack.push(5);									// stack : 5
	mstack.push(17);								// stack : 5 17

	cout << "top: " << mstack.top() << endl;

	mstack.pop();									// stack : 5

	cout << "size: " << mstack.size() << endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);									// stack : 5 3 5 737 0

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	cout << "it: " << *it << endl;

	++it;
	--it;

	std::advance (it, 2);

	cout << "distance: " << std::distance(it, ite) << endl;

	cout << "The last element is " << *std::prev(mstack.end()) << '\n';

	while (it != ite)
	{
		cout << "elem: " << *it << endl;
		++it;
	}

	std::stack<int> s(mstack);
	return 0;
}

int test_with_a_list()
{
	list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	cout << "top: " << mlist.back() << endl;

	mlist.pop_back();

	cout << "size: " << mlist.size() << endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);

	list<int>::iterator it = mlist.begin();
	list<int>::iterator ite = mlist.end();

	cout << "it: " << *it << endl;

	++it;
	--it;

	std::advance (it, 2);

	cout << "distance: " << std::distance(it, ite) << endl;

	cout << "The last element is " << *std::prev(mlist.end()) << '\n';

	while (it != ite)
	{
		cout << "elem: " << *it << endl;
		++it;
	}

	std::list<int> s(mlist);
	return 0;
}

int main( void ) {

	cout << "----- STACK -----" << endl;
	test_with_a_stack();

	cout << endl;

	cout << "----- LIST -----" << endl;
	test_with_a_list();
}