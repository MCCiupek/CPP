#ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"

// ************************************************************************** //
//                                 Cat Class                                  //
// ************************************************************************** //

class Cat : public Animal {

public:

	Cat( void );									// Default constructor
	Cat( Cat const & Cat );							// Copy constructor
	~Cat( void );									// Destructor

	Cat & 		operator= (const Cat &Cat );

	void		makeSound( void ) const;

};

std::ostream&		operator<<(std::ostream& stream, Cat const& Cat);

#endif /* __CAT_H__ */
