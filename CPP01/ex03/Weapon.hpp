#ifndef __WEAPON_H__
# define __WEAPON_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                                Zombie Class                                //
// ************************************************************************** //

class Weapon {

public:

	Weapon( std::string type );
	~Weapon( void );

	std::string		getType( void ) const ;
	void			setType( std::string type );

private:

	std::string		_type;

};

#endif /* __WEAPON_H__ */
