#include "Zombie.hpp"

Zombie::Zombie( void ) {

	return;
}

Zombie::~Zombie( void ) {

    std::cout << this->_name << " has been destroyed" << std::endl;
	return;
}

void	Zombie::announce( void ) {

    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

std::string	Zombie::getName( void ) const {

    return (this->_name);
}

void		Zombie::setName( std::string name ) {

    this->_name = name;
    return;
}