#ifndef __WRONG_CAT_H__
# define __WRONG_CAT_H__

#include "WrongAnimal.hpp"

// ************************************************************************** //
//                                 WrongCat Class                                  //
// ************************************************************************** //

class WrongCat : public WrongAnimal {

public:

	WrongCat( void );									// Default constructor
	WrongCat( WrongCat const & WrongCat );							// Copy constructor
	~WrongCat( void );									// Destructor

	WrongCat & 		operator= (const WrongCat &WrongCat );

	void		makeSound( void ) const;

};

std::ostream&		operator<<(std::ostream& stream, WrongCat const& WrongCat);

#endif /* __WRONG_CAT_H__ */
