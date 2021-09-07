#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap( void );									// Default constructor
	ScavTrap( std::string name, int hit_points, int energy_points, int attack_damage );						// Const constructor
	ScavTrap( ScavTrap const & ScavTrap );				// Copy constructor
	~ScavTrap( void );									// Destructor

    void guardGate( void );
};

#endif /* __SCAVTRAP_H__ */
