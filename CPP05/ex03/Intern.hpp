#ifndef __INTERN_H__
# define __INTERN_H__

# include <iostream>
# include <string>
# include <exception>

# include "Form.hpp"

# define NUM_FORM 3
enum FORMS { SCF, RRF, PPF };

// ************************************************************************** //
//                              Intern Class                               //
// ************************************************************************** //

class Form;

class Intern {

	public:

		Intern();
		Intern( Intern const &Copy );
		~Intern();

		Intern &		operator = ( const Intern & toCopy );

		Form *			makeForm( std::string const & form, std::string const & target ) ;
		Form *			newSCF( std::string const & target ) ;
		Form *			newRRF( std::string const & target ) ;
		Form *			newPPF( std::string const & target ) ;

		class 			UnknownFormException : public std::exception {};

	private:

		Form *			(Intern::*f[NUM_FORM])( std::string const & target );

};

std::ostream&	operator<<(std::ostream& stream, Intern const& Intern);

#endif /* __INTERN_H__ */