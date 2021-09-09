#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                             ClapTrap Class                                 //
// ************************************************************************** //

class ClapTrap {

public:

	ClapTrap( void );									// Default constructor
	ClapTrap( std::string name );
	ClapTrap( std::string name, int hit_points, int energy_points, int attack_damage );						// Const constructor
	ClapTrap( ClapTrap const & ClapTrap );				// Copy constructor
	~ClapTrap( void );									// Destructor

	ClapTrap & 	operator=( ClapTrap const & ClapTrap );	// Copy assignment operator

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string	getName( void ) const;
	void 		setName( std::string const name );

	int 		getHitPts( void ) const;
	void 		setHitPts( int const hit_points );

	int 		getEnergyPts( void ) const;
	void 		setEnergyPts( int const energy_points );

	int 		getAttackDamage( void ) const;
	void 		setAttackDamage( int const energy_points );

private:

	std::string _name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

	static const int defHitPts = 100;
	static const int defEnergyPts = 50;
	static const int defAttackDamage = 20;

};

std::ostream&	operator<<(std::ostream& stream, ClapTrap const& ClapTrap);


#endif /* __CLAPTRAP_H__ */
