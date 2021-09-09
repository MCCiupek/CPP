#ifndef __BRAIN_H__
# define __BRAIN_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Brain Class                                 //
// ************************************************************************** //

class Brain {

public:

	Brain( void );									// Default constructor
	Brain( std::string ideas[100] );
	Brain( Brain const & Brain );					// Copy constructor
	virtual ~Brain( void );							// Destructor

	Brain & 	operator=( Brain const & Brain );	// Copy assignment operator

	std::string&	getIdeas( void ) const;
	void 			setType( std::string ideas[100] );

	virtual void	makeSound( void ) const;

protected:

	std::string _ideas[100];

};

std::ostream&		operator<<(std::ostream& stream, Brain const& Brain);

#endif /* __BRAIN_H__ */
