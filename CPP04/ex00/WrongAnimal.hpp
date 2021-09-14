#ifndef __WRONG_ANIMAL_H__
# define __WRONG_ANIMAL_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                             WrongAnimal Class                              //
// ************************************************************************** //

class WrongAnimal {

public:

	WrongAnimal( void );										// Default constructor
	WrongAnimal( std::string type );
	WrongAnimal( WrongAnimal const & WrongAnimal );					// Copy constructor
	virtual ~WrongAnimal( void );									// Destructor

	WrongAnimal & 	operator=( WrongAnimal const & WrongAnimal );		// Copy assignment operator

	std::string		getType( void ) const;
	void 			setType( std::string const type );

	void			makeSound( void ) const;

protected:

	std::string _type;

};

std::ostream&		operator<<(std::ostream& stream, WrongAnimal const& WrongAnimal);


#endif /* __WRONG_ANIMAL_H__ */
