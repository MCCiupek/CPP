#ifndef __DOG_H__
# define __DOG_H__

#include "Animal.hpp"

// ************************************************************************** //
//                                 Dog Class                                  //
// ************************************************************************** //

class Dog : public Animal {

public:

	Dog( void );									// Default constructor
	Dog( Dog const & Dog );							// Copy constructor
	~Dog( void );									// Destructor

	Dog & 		operator= (const Dog &Dog );

	void		makeSound( void ) const;

};

std::ostream&		operator<<(std::ostream& stream, Dog const& Dog);

#endif /* __DOG_H__ */
