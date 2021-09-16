#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <exception>
#include <string>
#include <iostream>
#include <fstream>

/* CONSTRUCTORS, DESTRUCTORS */

PresidentialPardonForm::PresidentialPardonForm( void ) : 
	Form("PresidentialPardonForm", signGrade, execGrade) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : 
	Form("PresidentialPardonForm", signGrade, execGrade), _target(target) {

	return;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &Copy ) :
	Form(Copy.getName(), Copy.getSignGrade(), Copy.getExecGrade()) {

	return;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

PresidentialPardonForm & PresidentialPardonForm::operator= (const PresidentialPardonForm &Copy ) {

	if (this != &Copy)
		*this = Copy;
	return *this;
}

/* GETTERS, SETTERS */

std::string	const & PresidentialPardonForm::getTarget( void ) const {

	return (this->_target);
}

void	PresidentialPardonForm::setTarget( std::string const & target ) {

	this->_target = target;
	return ;
}

/* PUBLIC METHODS */

bool	PresidentialPardonForm::execute( Bureaucrat const & Bureaucrat ) const {

	std::ofstream file_out;

	if (this->getIsSigned()) {
		if (Bureaucrat.getGrade() > this->getExecGrade())
			throw Form::GradeTooLowException();
		std::cout << this->_target << " has received presidential pardon by Zafod Beeblebrox" << std::endl;
		return true;
	}
	return false;
}

std::ostream&	operator<<(std::ostream& stream, PresidentialPardonForm const& Copy)
{
	std::string signature = Copy.getIsSigned() ? "This PresidentialPardonForm is signed." : "This PresidentialPardonForm is not signed.";

	stream << Copy.getName() 
		<< " with signing grade " << Copy.getSignGrade() 
		<< " and execution grade " << Copy.getExecGrade() << ". "
		<< signature;
	return (stream);
}
