#ifndef __SCF_H__
# define __SCF_H__

# include "Form.hpp"

# define TREES "\n\
											# #### ####\n\
										 ### \\/#|### |/####\n\
										 ##\\/#/ \\||/##/_/##/_#\n\
									    ###  \\/###|/ \\/ # ###\n\
									  ##_\\_#\\_\\## | #/###_/_####\n\
									 ## #### # \\ #| /  #### ##/##\n\
									  __#_--###`  |{,###---###-~\n\
												\\ }{\n\
												  }}{\n\
												  }}{\n\
											 ejm  {{}\n\
											, -=-~{ .-^- _\n\
												  `}\n\
												   {\n\
				&&& &&  & &&\n\
		 	  && &\\/&\\|& ()|/ @, &&\n\
			  &\\/(/&/&||/& /_/)_&/_&\n\
		   &() &\\/&|()|/&\\/ '%\" & ()\n\
		  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
		&&   && & &| &| /& & % ()& /&&\n\
		 ()&_---()&\\&\\|&&-&&--%---()~\n\
			  &&    \\|||\n\
					 |||\n\
					 |||\n\
					 |||\n\
			  , -=-~  .-^- _\n\
ejm97         `                                 ###\n\
											   #o###\n\
											 #####o###\n\
											#o#\\#|#/###\n\
											 ###\\|/#o#\n\
											  # }|{ #\n\
										 ejm97  }|{"

// ************************************************************************** //
//                      ShrubberyCreationForm Class                           //
// ************************************************************************** //

class ShrubberyCreationForm : public Form {

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string const & target );
		ShrubberyCreationForm( ShrubberyCreationForm const & Copy );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &	operator = ( const ShrubberyCreationForm & toCopy );

		std::string	const &	getTarget( void ) const ;
		void				setTarget( std::string const & target ) ;

		bool				execute ( Bureaucrat const & executor ) const ;

	private:

		static const unsigned int	signGrade = 145;
		static const unsigned int	execGrade = 137;

		std::string			_target;

};

#endif /* __SCF_H__ */