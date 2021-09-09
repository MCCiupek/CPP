#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// ************************************************************************** //
//                           DiamondTrap Class                                //
// ************************************************************************** //

class DiamondTrap : public FragTrap, public	ScavTrap {

public:

	DiamondTrap( void );									// Default constructor
	DiamondTrap( std::string name );						// Const constructor
	DiamondTrap( std::string name, int hit_points, int energy_points, int attack_damage );						// Const constructor
	DiamondTrap( DiamondTrap const & DiamondTrap );				// Copy constructor
	~DiamondTrap( void );									// Destructor

	DiamondTrap & operator= (const DiamondTrap &DiamondTrap );

	std::string	getName( void ) const;
	void 		setName( std::string const name );

	std::string	getCPName( void ) const;
	void 		setCPName( std::string const name );

	using		ScavTrap::attack;

	using		FragTrap::getHitPts;
	using		FragTrap::setHitPts;

	using		ScavTrap::getEnergyPts;
	using		ScavTrap::setEnergyPts;

	using		FragTrap::getAttackDamage;
	using		FragTrap::setAttackDamage;

	void 		whoAmI();

private:

	std::string	_name;
};

std::ostream&	operator<<(std::ostream& stream, DiamondTrap const& DiamondTrap);

#endif /* __DIAMONDTRAP_H__ */
