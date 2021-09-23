#include "Span.hpp"
# include <algorithm>

using std::max_element;
using std::min_element;
using std::nth_element;
using std::endl;
using std::abs;

/* OPERATORS */

Span &			Span::operator=( Span const & toCopy ) {

	if ( this != &toCopy ) {
		_N = toCopy._N;
		_vec.resize(toCopy._vec.size());
		_vec = toCopy._vec;
	}
	return *this;
}

/* METHODS */

void			Span::addNumber( int nb ) {

	if ( _vec.size() >= _N )
		throw Span::IsFullException();
	_vec.push_back( nb );
}

void			Span::addNumber( vector<int>::const_iterator first, vector<int>::const_iterator last ) {

	if ( _N - _vec.size() < static_cast<unsigned long>(last - first) )
		throw Span::IsFullException();
	_vec.insert( _vec.end(), first, last );
}

unsigned int 	Span::shortestSpan( void ) const {

	vector<int>	copy(_vec);
	vector<unsigned int> diff;

	if ( _vec.size() < 2 )
		throw Span::NoSpan();
	diff.resize(_vec.size() - 1);
	std::sort(copy.begin(), copy.end());
	if (std::adjacent_find(copy.begin(), copy.end()) != copy.end())
		return 0;
	std::transform (copy.begin() + 1, copy.end(), copy.begin(), diff.begin(), std::minus<int>());
	return *min_element(diff.begin(), diff.end());
}

unsigned int 	Span::longestSpan( void ) const {

	if ( _vec.size() < 2 )
		throw Span::NoSpan();
	int max = *max_element(_vec.begin(), _vec.end());
	int min = *min_element(_vec.begin(), _vec.end());
	unsigned int res = max - min;
	return res;
}

void	print_vec( std::ostream & stream, vector<int> v, unsigned int print_max = 10 ) {

	if (v.size() <= print_max) {
		for (unsigned int i = 0; i < v.size(); i++)
			stream << v[i] << " ";
	}
	else {
		for (unsigned int i = 0; i < print_max / 2; i++)
			stream << v[i] << " ";
		stream << "... ";
		for (unsigned int i = v.size() - print_max / 2; i < v.size(); i++)
			stream << v[i] << " ";
	}
}

std::ostream & operator << (std::ostream & stream, Span &Span) {

	print_vec( stream, Span.getVec() );
	return stream;
}
