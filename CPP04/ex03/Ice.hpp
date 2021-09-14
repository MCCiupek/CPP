#ifndef __ICE_H__
# define __ICE_H__

# include "AMateria.hpp"
# include <string>

// ************************************************************************** //
//                                 Ice Class                                  //
// ************************************************************************** //

class Ice : public AMateria {

public:

	Ice( void );									// Default constructor
	Ice( Ice const & Ice );							// Copy constructor
	~Ice( void );									// Destructor

	Ice & 		operator= (const Ice &Ice );

	AMateria*	clone() const;
    void		use( ICharacter& target );

};

std::ostream&		operator<<(std::ostream& stream, Ice const& Ice);

#endif /* __ICE_H__ */
