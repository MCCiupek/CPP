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
	
	bool	 	operator>( Fixed const & Number ) const;
	bool	 	operator<( Fixed const & Number ) const;
	bool	 	operator>=( Fixed const & Number ) const;
	bool	 	operator<=( Fixed const & Number ) const;
	bool	 	operator==( Fixed const & Number ) const;

	Fixed 	 	operator+( Fixed const & Number ) const;
	Fixed 	 	operator-( Fixed const & Number ) const;
	Fixed 	 	operator*( Fixed const & Number ) const;
	Fixed 		operator/( Fixed const & Number ) const;

	Fixed &	 	operator++ ( void );
	Fixed 	 	operator++ ( int );
	Fixed &	 	operator-- ( void );
	Fixed 	 	operator-- ( int );

	static Fixed &	min( Fixed &a, Fixed &b);
	static Fixed &	max( Fixed &a, Fixed &b);
	static const Fixed &	min( Fixed const &a, Fixed const &b);
	static const Fixed &	max( Fixed const &a, Fixed const &b);

	int 		getRawBits( void ) const;
	void 		setRawBits( int const raw );

	float 		toFloat(void) const;
	int 		toInt(void) const;

private:

	const static int	_nbBits = NB_BITS;

	int			_value;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & Number );

#endif /* __FIXED_H__ */
