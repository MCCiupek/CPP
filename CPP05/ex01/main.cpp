#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	/* INVALID FORMS */
	try {
		Form	TimeTravelAuth("Time Travel authorization", 1, 100);
		Form	Mariage("Mariage Contract", 200, 150);
		Form	ArrestWarrant("Intergalactical Arrest Warrant", 150, -1);
	}
	catch (Form::GradeTooHighException & e) {
		std::cout << RED << "Grade too high" << NO_COLOR << std::endl;
	}
	catch (Form::GradeTooLowException & e) {
		std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
	}

	/* UNAUTHORIZED SIGNATURE */
	try {
		Bureaucrat  morty("morty", 50);
		std::cout << morty << std::endl;
		
		Bureaucrat  rick("rick", 1);
		std::cout << rick << std::endl;

		Form	TimeTravelAuth("Time Travel authorization", 1, 100);
		
		try {
			rick.signForm(TimeTravelAuth);
			TimeTravelAuth.beSigned(rick);
		}
		catch (Form::GradeTooLowException & e ) {
			std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
		}

		try {
			morty.signForm(TimeTravelAuth);
			TimeTravelAuth.beSigned(morty);
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


	return 0;
}