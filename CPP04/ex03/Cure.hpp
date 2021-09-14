#ifndef __CURE_H__
# define __CURE_H__

# include "AMateria.hpp"
# include <string>

// ************************************************************************** //
//                                 Cure Class                                 //
// ************************************************************************** //

class Cure : public AMateria {

public:

	Cure( void );									// Default constructor
	Cure( Cure const & Cure );						// Copy constructor
	~Cure( void );									// Destructor

	Cure & 		operator= ( const Cure &Cure );

	AMateria*	clone() const;
	void		use( ICharacter& target );

};

std::ostream&		operator<<(std::ostream& stream, Cure const& Cure);

#endif /* __CURE_H__ */
