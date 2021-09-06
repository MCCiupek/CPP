#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>

# define NB_BITS 8

// ************************************************************************** //
//                                Fixed Class                                 //
// ************************************************************************** //

class Fixed {

public:

	Fixed( void );									// Default constructor
	Fixed( int const n );							// Const Int constructor
	Fixed( float const f );							// Const Float constructor
	Fixed( Fixed const & Number );					// Copy constructor
	~Fixed( void );									// Destructor

	Fixed & 	operator=( Fixed const & Number );	// Copy assignment operator

	int 		getRawBits( void ) const;
	void 		setRawBits( int const raw );

	float 		toFloat(void) const;
	int 		toInt(void) const;

private:

	static int	_nbBits;

	int			*_fixed;
	int			_binary_point;
	int			_value;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & Number );

#endif /* __FIXED_H__ */
