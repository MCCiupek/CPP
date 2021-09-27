#ifndef __ARRAY_H__
# define __ARRAY_H__

# include <iostream>
# include <string>
# include <exception>

// ************************************************************************** //
//                                Array Class                                 //
// ************************************************************************** //

template<typename T>
class Array {

public:

	Array( void ) : _array(new T[0]), _size(0) {};
	Array( unsigned int n ) : _array(new T[n]), _size(n) {};
	Array( Array const & Copy ) { this->_array = Copy->_array; };
	virtual ~Array( void ) { delete this->_array; };

	Array & 		operator=( Array & Copy );
	T				operator[]( unsigned int i );

	unsigned int	size( void );

	void			setArray( unsigned int i, T elem );

	class 			OutOfLimits : public std::exception {};

private:

	T *				_array;
	unsigned int	_size;

};

template<typename T>
std::ostream&	operator<<(std::ostream& stream, Array<T> const& Array);

/* ACCESSORS */

template<typename T>
void			Array<T>::setArray( unsigned int i, T elem ) {

	this->_array[i] = elem;
}

/* OPERATORS */

template<typename T>
Array<T> & 	Array<T>::operator=( Array<T> & Copy ) {

	this->_size = Copy.size();
	this->_array = new T[Copy.size()];

	for (unsigned int i = 0; i < this->size(); i++ )
		this->_array[i] = Copy[i];
	return *this;
}

template<typename T>
T			Array<T>::operator[]( unsigned int i ) {

	if (i >= this->size())
		throw Array<T>::OutOfLimits();
	return this->_array[i];
}

/* METHODS */

template<typename T>
unsigned int	Array<T>::size( void ) {

	return this->_size;
}

template<typename T>
std::ostream&	operator<<(std::ostream& stream, Array<T> & Array)
{
	if (!Array.size())
		stream << "(null)" << std::endl;
	for (unsigned int i = 0; i < Array.size(); i++)
		stream << "[" << i << "]: " << Array[i] << std::endl;
	return (stream);
}

#endif /* __ARRAY_H__ */
