#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

/* CONSTRUCTORS, DESTRUCTORS */

ShrubberyCreationForm::ShrubberyCreationForm( void ) : 
	Form("ShrubberyCreationForm", signGrade, execGrade) {

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : 
	Form("ShrubberyCreationForm", signGrade, execGrade), _target(target) {

	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &Copy ) :
	Form(Copy.getName(), Copy.getSignGrade(), Copy.getExecGrade()) {

	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

ShrubberyCreationForm & ShrubberyCreationForm::operator= (const ShrubberyCreationForm &Copy ) {

	if (this != &Copy)
		*this = Copy;
	return *this;
}

/* GETTERS, SETTERS */

std::string	const & ShrubberyCreationForm::getTarget( void ) const {

	return (this->_target);
}

void	ShrubberyCreationForm::setTarget( std::string const & target ) {

	this->_target = target;
	return ;
}

/* PUBLIC METHODS */

bool	ShrubberyCreationForm::execute( Bureaucrat const & Bureaucrat ) const {

	std::ofstream file_out;
	const char *filename = (this->_target + "_shrubbery").c_str();

	if (this->getIsSigned()) {
		if (Bureaucrat.getGrade() > this->getExecGrade())
			throw Form::GradeTooLowException();
		file_out.open(filename, std::ios_base::out);
		if (file_out.is_open()) {
			file_out << TREES << std::endl;
			file_out.close();
		}
		else {
			std::cout << "Execution failed: Could not open file " << this->getTarget() << "_shrubbery." << std::endl;
			return false;
		}
		return true;
	}
	return false;
}

std::ostream&	operator<<(std::ostream& stream, ShrubberyCreationForm const& Copy)
{
	std::string signature = Copy.getIsSigned() ? "This ShrubberyCreationForm is signed." : "This ShrubberyCreationForm is not signed.";

	stream << Copy.getName() 
		<< " with signing grade " << Copy.getSignGrade() 
		<< " and execution grade " << Copy.getExecGrade() << ". "
		<< signature;
	return (stream);
}
