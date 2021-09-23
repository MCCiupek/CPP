#ifndef __MUTANT_STACK_H__
# define __MUTANT_STACK_H__

# include <algorithm>
# include <stack>
# include <deque>
# include <exception>
# include <iostream>

using std::stack;
using std::deque;
using std::exception;

// ************************************************************************** //
//                            	MutantStack Class                             //
// ************************************************************************** //

template <typename T>
class MutantStack : public stack<T> {

	public:

		typedef T * iterator;
	
		MutantStack<T>::iterator begin() { init_deq(); return &_deq.front(); }
		MutantStack<T>::iterator end() { init_deq(); return &_deq.back() + 1; }
	
		void	init_deq( void ) {

			stack<T> cpy = *this;

			for (unsigned long i = 0; i < this->size(); i++) {
				_deq.push_front( cpy.top() );
				cpy.pop();
			}
		} ;

	private:

	deque<T>	_deq;

};

#endif /* __MUTANT_STACK_H__ */
