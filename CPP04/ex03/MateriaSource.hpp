#ifndef __MATERIASOURCE_H__
# define __MATERIASOURCE_H__

# include <iostream>
# include "IMateriaSource.hpp"

// ************************************************************************** //
//                              MateriaSource Class                           //
// ************************************************************************** //


class MateriaSource : public IMateriaSource {

	public:

		MateriaSource();
		MateriaSource( MateriaSource const &Copy );
		~MateriaSource();

		MateriaSource &	operator = ( const MateriaSource & toCopy );

		void		learnMateria( AMateria* m );
		AMateria*	createMateria( std::string const & type );

	protected:

	private:

		AMateria *  _inventory[4];

};

#endif /* __MATERIASOURCE_H__ */