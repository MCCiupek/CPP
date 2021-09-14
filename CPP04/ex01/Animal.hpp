#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Animal Class                                 //
// ************************************************************************** //

class Animal {

public:

	Animal( void );										// Default constructor
	Animal( std::string type );
	Animal( Animal const & Animal );					// Copy constructor
	virtual ~Animal( void );									// Destructor

	Animal & 	operator=( Animal const & Animal );		// Copy assignment operator

	std::string		getType( void ) const;
	void 			setType( std::string const type );

	virtual void	makeSound( void ) const;

protected:

	std::string _type;

};

std::ostream&		operator<<(std::ostream& stream, Animal const& Animal);


#endif /* __ANIMAL_H__ */
