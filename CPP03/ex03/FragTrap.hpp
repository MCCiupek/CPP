#ifndef __FragTrap_H__
# define __FragTrap_H__

#include "ClapTrap.hpp"

// ************************************************************************** //
//                             FragTrap Class                                 //
// ************************************************************************** //

class FragTrap : virtual public ClapTrap {

public:

	FragTrap( std::string name );						// Const constructor
	FragTrap( std::string name, int hit_points, int energy_points, int attack_damage );						// Const constructor
	FragTrap( FragTrap const & FragTrap );				// Copy constructor
	~FragTrap( void );									// Destructor

	FragTrap & operator= (const FragTrap &FragTrap );

	void attack(std::string const & target);
    void highFivesGuys( void );

protected:
	
	FragTrap( void );									// Default constructor
};

std::ostream&	operator<<(std::ostream& stream, FragTrap const& FragTrap);

#endif /* __FragTrap_H__ */
