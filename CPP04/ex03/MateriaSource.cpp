#include "MateriaSource.hpp"
#include <iostream>

/* CONSTRUCTORS, DESTRUCTORS */

MateriaSource::MateriaSource( void ) {

	return;
}

MateriaSource::MateriaSource( const MateriaSource &Copy ) {

	*this = Copy;
	return;
}

MateriaSource::~MateriaSource( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

MateriaSource & MateriaSource::operator= (const MateriaSource &Copy ) {

	if (this != &Copy)
		*this->_inventory = *Copy._inventory;
	return *this;
}

/* PUBLIC METHODS */

void MateriaSource::learnMateria( AMateria* m ) {

    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m->clone();
            return ;
        }
    }
    return ;
}

AMateria* MateriaSource::createMateria(std::string const & type) {

    for (int i = 0; i < 4; i++) {
        if (_inventory[i]->getType() == type)
            return _inventory[i]->clone();
    }
    return 0;
}
