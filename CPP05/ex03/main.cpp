#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Bureaucrat  morty("morty", 50);
		std::cout << morty << std::endl;
		
		Bureaucrat  rick("rick", 1);
		std::cout << rick << std::endl;

		ShrubberyCreationForm 	sc("sc");
		RobotomyRequestForm 	rr("rr");
		PresidentialPardonForm 	pp("pp");
		
		try {
			sc.beSigned(rick);
			sc.execute(rick);
		}
		catch (Form::GradeTooLowException & e ) {
			std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
		}

		try {
			rr.beSigned(rick);
			rr.execute(rick);
		}
		catch (Form::GradeTooLowException & e ) {
			std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
		}

		try {
			pp.beSigned(rick);
			pp.execute(rick);
		}
		catch (Form::GradeTooLowException & e ) {
			std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
		}
	}
	catch (Form::GradeTooHighException & e) {
		std::cout << RED << "Grade too high" << NO_COLOR << std::endl;
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
	}
	try
	{
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	catch (Intern::UnknownFormException & e) {
		std::cout << RED << "Unknown form type" << NO_COLOR << std::endl;
	}
	try
	{
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("blablabla", "Bender");
		delete rrf;
	}
	catch (Intern::UnknownFormException & e) {
		std::cout << RED << "Unknown form type" << NO_COLOR << std::endl;
	}
	return 0;
}