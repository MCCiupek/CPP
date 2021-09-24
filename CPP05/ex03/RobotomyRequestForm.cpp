#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

/* CONSTRUCTORS, DESTRUCTORS */

RobotomyRequestForm::RobotomyRequestForm( void ) : 
	Form("RobotomyRequestForm", signGrade, execGrade) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : 
	Form("RobotomyRequestForm", signGrade, execGrade), _target(target) {

	return;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &Copy ) :
	Form(Copy.getName(), Copy.getSignGrade(), Copy.getExecGrade()) {

	return;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

RobotomyRequestForm & RobotomyRequestForm::operator= (const RobotomyRequestForm &Copy ) {

	if (this != &Copy)
		*this = Copy;
	return *this;
}

/* GETTERS, SETTERS */

std::string	const & RobotomyRequestForm::getTarget( void ) const {

	return (this->_target);
}

void	RobotomyRequestForm::setTarget( std::string const & target ) {

	this->_target = target;
	return ;
}

/* PUBLIC METHODS */

bool	RobotomyRequestForm::execute( Bureaucrat const & Bureaucrat ) const {

	std::ofstream file_out;

	if (this->getIsSigned()) {
		if (Bureaucrat.getGrade() > this->getExecGrade())
			throw Form::GradeTooLowException();
		std::cout << DRILL << std::endl;
		if (rand() % 2)
			std::cout << this->_target << " has been robotomized successfully." << std::endl;
		else
			std::cout << this->_target << " robotomization has failed." << std::endl;
		return true;
	}
	return false;
}

std::ostream&	operator<<(std::ostream& stream, RobotomyRequestForm const& Copy)
{
	std::string signature = Copy.getIsSigned() ? "This RobotomyRequestForm is signed." : "This RobotomyRequestForm is not signed.";

	stream << Copy.getName() 
		<< " with signing grade " << Copy.getSignGrade() 
		<< " and execution grade " << Copy.getExecGrade() << ". "
		<< signature;
	return (stream);
}
