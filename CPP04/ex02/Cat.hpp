#ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

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

private:

	Brain *		_brain;

};

std::ostream&		operator<<(std::ostream& stream, Cat const& Cat);

#endif /* __CAT_H__ */
