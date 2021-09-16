#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat  morty("morty", 1);
		std::cout << morty;

		Bureaucrat  rick("rick", 150);
		std::cout << rick;

		Bureaucrat  jerry("jerry", 151);
		std::cout << jerry;

		Bureaucrat  summer("summer", 0);
		std::cout << summer;

		Bureaucrat  beth("beth", -50);
		std::cout << beth;
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << RED << "Grade too high" << NO_COLOR << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
	}

	try {
		Bureaucrat  summer("summer", 0);
		std::cout << summer;

		Bureaucrat  beth("beth", -50);
		std::cout << beth;
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << RED << "Grade too high" << NO_COLOR << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
	}

	try {
		Bureaucrat  summer("summer", 100);
		summer.incGrade();
		std::cout << summer;

		Bureaucrat  beth("beth", 150);
		beth.decGrade(5);
		std::cout << beth;
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << RED << "Grade too high" << NO_COLOR << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << RED << "Grade too low" << NO_COLOR << std::endl;
	}

	return 0;
}