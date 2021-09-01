#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

#include <iostream>
# include <string>

// ************************************************************************** //
//                                Zombie Class                                //
// ************************************************************************** //

class Zombie {

public:

	Zombie( void );
	~Zombie( void );

	std::string	getName( void ) const ;
	void		setName( std::string name );
	void		announce( void );

private:
	std::string	_name;

};

// ************************************************************************** //
//                                  Functions                                 //
// ************************************************************************** //

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
