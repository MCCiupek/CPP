#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include <iostream>
# include "ICharacter.hpp"

// ************************************************************************** //
//                              Character Class                               //
// ************************************************************************** //


class Character : virtual public ICharacter {

	public:

		Character();
		Character( std::string name );
		Character( Character const &Copy );
		~Character();

		Character &	operator = ( const Character & toCopy );

		std::string	const & getName( void ) const ;

		void equip( AMateria* m );
        void unequip( int idx );
        void use( int idx, ICharacter& target );

	private:

		std::string     _name;
		AMateria *      _inventory[4];

};

std::ostream&	operator<<(std::ostream& stream, AMateria const& AMateria);

#endif /* __CHARACTER_H__ */