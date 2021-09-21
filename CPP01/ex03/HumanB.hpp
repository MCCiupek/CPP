#ifndef __HUMAN_B_H__
# define __HUMAN_B_H__

# include <iostream>
# include <string>
# include "Weapon.hpp"

// ************************************************************************** //
//                                HumanB Class                                //
// ************************************************************************** //

class HumanB {

public:

	HumanB( std::string name );
	~HumanB( void );

	std::string	getName( void ) const ;
	void		setName( std::string name );
	Weapon*		getWeapon( void ) const ;
	void		setWeapon( Weapon& weapon );
	void		attack( void ) const ;

private:
	
	std::string	_name;
	Weapon*		_weapon;

};

#endif /* __HUMAN_B_H__ */
