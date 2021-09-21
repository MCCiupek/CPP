#ifndef __HUMAN_A_H__
# define __HUMAN_A_H__

# include <iostream>
# include <string>
# include "Weapon.hpp"

// ************************************************************************** //
//                                HumanA Class                                //
// ************************************************************************** //

class HumanA {

public:

	HumanA( std::string name, Weapon& weapon );
	~HumanA( void );

	std::string	getName( void ) const ;
	void		setName( std::string name );
	Weapon&		getWeapon( void ) const ;
	void		setWeapon( Weapon& weapon );
	void		attack( void ) const ;

private:

	std::string	_name;
	Weapon&		_weapon;

};

#endif /* __HUMAN_A_H__ */
