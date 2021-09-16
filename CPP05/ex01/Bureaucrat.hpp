#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <string>
# include <exception>

# include "Form.hpp"

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
//                              Bureaucrat Class                               //
// ************************************************************************** //

class Form;

class Bureaucrat {

	public:

		Bureaucrat();
		Bureaucrat( const std::string name, unsigned int grade );
		Bureaucrat( Bureaucrat const &Copy );
		~Bureaucrat();

		Bureaucrat &	operator = ( const Bureaucrat & toCopy );

		std::string	const &	getName( void ) const ;
		unsigned int 		getGrade( void ) const ;

		void 				incGrade( unsigned int i = 1 ) ;
		void 				decGrade( unsigned int i = 1 ) ;

		void				checkGrade( int grade ) ;
		void				signForm( Form const & Form ) ;

		class 		GradeTooHighException : public std::exception {};
		class 		GradeTooLowException : public std::exception {};

	private:

		const std::string		_name;
		unsigned int			_grade;

};

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const& Bureaucrat);

#endif /* __BUREAUCRAT_H__ */