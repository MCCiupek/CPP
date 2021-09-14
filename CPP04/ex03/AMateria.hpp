#ifndef __AMATERIA_H__
# define __AMATERIA_H__

# include <string>
# include "ICharacter.hpp"

class ICharacter;

// ************************************************************************** //
//                             AMateria Class                                 //
// ************************************************************************** //

class AMateria
{
	protected:

		std::string _type;

	public:

		AMateria( void );
		AMateria( std::string const & type );
		AMateria( AMateria const & Copy );
		virtual ~AMateria( void );

		AMateria & 		    operator= ( const AMateria &AMateria );

		std::string const & getType() const; //Returns the materia type
		void		        setType( std::string const type );

		virtual AMateria*   clone() const = 0;
		virtual void        use( ICharacter& target );
};

#endif /* __AMATERIA_H__ */