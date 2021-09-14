#ifndef __IMATERIASOURCE_H__
# define __IMATERIASOURCE_H__

# include <string>
# include "ICharacter.hpp"

// ************************************************************************** //
//                             IMateriaSource Class                           //
// ************************************************************************** //

class IMateriaSource
{
    public:

        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria* m) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif /* __IMATERIASOURCE_H__ */