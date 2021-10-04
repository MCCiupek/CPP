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

	Brain & 		operator=( Brain const & Brain );	// Copy assignment operator

	std::string const*	getIdeas( void ) const;
	void 			setIdeas( void );
	void 			setIdeas( std::string const ideas[100] );

	std::string		getIdea(void) const;

protected:

	std::string		_ideas[100];

};

std::ostream&		operator<<(std::ostream& stream, Brain const& Brain);

#endif /* __BRAIN_H__ */
