#ifndef __FORM_H__
# define __FORM_H__

# include <iostream>
# include <string>
# include <exception>

# include "Bureaucrat.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1

/* Colors */

# define BLACK "\033[1;30m"
# define GREY "\033[1;90m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define NO_COLOR "\033[0;37m"


// ************************************************************************** //
//                              Form Class                               //
// ************************************************************************** //

class Bureaucrat;

class Form {

	public:

		Form();
		Form( const std::string name, unsigned int sign_grade, unsigned int exec_grade );
		Form( Form const &Copy );
		~Form();

		Form &	operator = ( const Form & toCopy );

		std::string	const &	getName( void ) const ;
		bool		 		getIsSigned( void ) const ;
		unsigned int 		getSignGrade( void ) const ;
		unsigned int 		getExecGrade( void ) const ;

		void		 		beSigned( Bureaucrat const & Bureaucrat ) ;
		void				checkGrade( int grade ) ;

		class 		GradeTooHighException : public std::exception {};
		class 		GradeTooLowException : public std::exception {};

	private:

		const std::string		_name;
		bool					_is_signed;
		const unsigned int		_sign_grade;
		const unsigned int		_exec_grade;

};

std::ostream&	operator<<(std::ostream& stream, Form const& Form);

#endif /* __FORM_H__ */