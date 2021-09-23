#ifndef __SPAN_H__
# define __SPAN_H__

# include <algorithm>
# include <vector>
# include <exception>
# include <iostream>

using std::vector;
using std::exception;

// ************************************************************************** //
//                                	Span Class                                //
// ************************************************************************** //

class Span {

	public:
	
		Span( void )  : _N(0) {} ;
		Span( unsigned int N ) : _N(N) {} ;
		Span( Span const & toCopy ) { *this = toCopy; };
		~Span( void ) {};

		Span &			operator=( Span const & toCopy );

		class IsFullException : public exception {
			public: const char * what() const throw() { return "Object is full.";}
		};
		class NoSpan : public exception {
			public: const char * what() const throw() { return "Object has less than 2 elements.";}
		};

		unsigned int	getN( void ) const { return _N; };
		vector<int>		getVec( void ) const { return _vec; };

		void			addNumber( int nb );
		void 			addNumber( vector<int>::const_iterator first, vector<int>::const_iterator last );
		unsigned int 	shortestSpan( void ) const ;
		unsigned int 	longestSpan( void ) const ;
	
	private:

		unsigned int	_N;
		vector<int>		_vec;
};

std::ostream & operator << (std::ostream & stream, Span &Span);

#endif /* __SPAN_H__ */
