#ifndef __FragTrap_H__
# define __FragTrap_H__

#include "ClapTrap.hpp"

// ************************************************************************** //
//                             FragTrap Class                                 //
// ************************************************************************** //

class FragTrap : public ClapTrap {

public:

	FragTrap( void );									// Default constructor
	FragTrap( std::string name );						// Const constructor
	FragTrap( std::string name, int hit_points, int energy_points, int attack_damage );						// Const constructor
	FragTrap( FragTrap const & FragTrap );				// Copy constructor
	~FragTrap( void );									// Destructor

	FragTrap & operator= (const FragTrap &FragTrap );

    void highFivesGuys( void );

	static const int defHitPts = 100;
	static const int defEnergyPts = 100;
	static const int defAttackDamage = 30;
};

std::ostream&	operator<<(std::ostream& stream, FragTrap const& FragTrap);

#endif /* __FragTrap_H__ */
