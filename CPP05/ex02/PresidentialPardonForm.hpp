#ifndef __PPF_H__
# define __PPF_H__

# include "Form.hpp"

// ************************************************************************** //
//                      PresidentialPardonForm Class                          //
// ************************************************************************** //

class PresidentialPardonForm : public Form {

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( std::string const & target );
		PresidentialPardonForm( PresidentialPardonForm const & Copy );
		~PresidentialPardonForm();

		PresidentialPardonForm &	operator = ( const PresidentialPardonForm & toCopy );

		std::string	const &	getTarget( void ) const ;
		void				setTarget( std::string const & target ) ;

		bool				execute ( Bureaucrat const & executor ) const ;

	private:

		static const unsigned int	signGrade = 25;
		static const unsigned int	execGrade = 5;

		std::string			_target;

};

#endif /* __PPF_H__ */