#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

#include "ClapTrap.hpp"

// ************************************************************************** //
//                             ScavTrap Class                                 //
// ************************************************************************** //

class ScavTrap : public ClapTrap {

public:

	ScavTrap( std::string name );						// Const constructor
	ScavTrap( std::string name, int hit_points, int energy_points, int attack_damage );						// Const constructor
	ScavTrap( ScavTrap const & ScavTrap );				// Copy constructor
	~ScavTrap( void );									// Destructor

	ScavTrap & operator= (const ScavTrap &ScavTrap );

    void guardGate( void );
	void attack(std::string const & target);

private:

	ScavTrap( void );									// Default constructor

};

std::ostream&	operator<<(std::ostream& stream, ScavTrap const& ScavTrap);

#endif /* __SCAVTRAP_H__ */
