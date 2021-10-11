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
	Array( Array const & Copy ) { *this = Copy; };
	virtual ~Array( void ) { delete [] this->_array; };

	Array & 		operator=( Array const & Copy );
	T &				operator[]( unsigned int i );
	T const &		operator[]( unsigned int i ) const;

	unsigned int	size( void ) const ;

	void			setArray( unsigned int i, T elem );

	class 			OutOfLimits : public std::exception { 
		public:
			const char * what() const throw() {
				return "Index is out of limits";
		}
};


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
Array<T> & 	Array<T>::operator=( Array<T> const & Copy ) {

	delete [] this->_array;
	this->_size = Copy.size();
	this->_array = new T[Copy.size()];
	for (unsigned int i = 0; i < this->size(); i++ )
		this->_array[i] = Copy[i];
	return *this;
}

template<typename T>
T &			Array<T>::operator[]( unsigned int i ) {

	if (i >= this->size())
		throw Array<T>::OutOfLimits();
	return this->_array[i];
}

template<typename T>
T const &	Array<T>::operator[]( unsigned int i ) const {

	if (i >= this->size())
		throw Array<T>::OutOfLimits();
	return this->_array[i];
}

/* METHODS */

template<typename T>
unsigned int	Array<T>::size( void ) const {

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
