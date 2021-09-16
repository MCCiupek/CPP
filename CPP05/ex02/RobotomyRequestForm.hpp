#ifndef __RRF_H__
# define __RRF_H__

# include "Form.hpp"

# define DRILL "* drilling noises *"

// ************************************************************************** //
//                      RobotomyRequestForm Class                             //
// ************************************************************************** //

class RobotomyRequestForm : public Form {

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( std::string const & target );
		RobotomyRequestForm( RobotomyRequestForm const & Copy );
		~RobotomyRequestForm();

		RobotomyRequestForm &	operator = ( const RobotomyRequestForm & toCopy );

		std::string	const &	getTarget( void ) const ;
		void				setTarget( std::string const & target ) ;

		bool				execute ( Bureaucrat const & executor ) const ;

		

	private:

		static const unsigned int	signGrade = 72;
		static const unsigned int	execGrade = 45;

		std::string			_target;

};

#endif /* __RRF_H__ */