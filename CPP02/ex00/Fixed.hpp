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
	Fixed( Fixed const & Number );					// Copy constructor
	~Fixed( void );									// Destructor

	Fixed & 	operator=( Fixed const & Number );	// Copy assignment operator

	int 		getRawBits( void ) const;
	void 		setRawBits( int const raw );

private:

	const static int	_nbBits = NB_BITS;

	int			_value;

};

#endif /* __FIXED_H__ */
