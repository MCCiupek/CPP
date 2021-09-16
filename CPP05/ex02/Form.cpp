#include "Form.hpp"
#include <exception>

/* CONSTRUCTORS, DESTRUCTORS */

Form::Form( void ) : 
	_name("default"), 
	_is_signed(false), 
	_sign_grade(MIN_GRADE), 
	_exec_grade(MIN_GRADE) {

	return;
}

Form::Form( const std::string name, unsigned int sign_grade, unsigned int exec_grade ) : 
	_name(name), 
	_is_signed(false), 
	_sign_grade(sign_grade), 
	_exec_grade(exec_grade) {

	std::cout << "Creating Form " << *this << std::endl;
	checkGrade(this->_sign_grade);
	checkGrade(this->_exec_grade);
}

Form::Form( const Form &Copy ) :
	_name(Copy.getName()), 
	_is_signed(Copy.getIsSigned()), 
	_sign_grade(Copy.getSignGrade()), 
	_exec_grade(Copy.getExecGrade()) {

	checkGrade(this->_sign_grade);
	checkGrade(this->_exec_grade);
	return;
}

Form::~Form( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

Form & Form::operator= (const Form &Copy ) {

	if (this != &Copy)
		*this = Copy;
	return *this;
}

/* GETTERS, SETTERS */

std::string	const & Form::getName( void ) const {

	return (this->_name);
}

bool	Form::getIsSigned( void ) const {

	return (this->_is_signed);
}

unsigned int	Form::getSignGrade( void ) const {

	return (this->_sign_grade);
}

unsigned int	Form::getExecGrade( void ) const {

	return (this->_exec_grade);
}

/* PUBLIC METHODS */

void	Form::checkGrade( int grade ) {

	if (grade < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Form::GradeTooLowException();
	return ;
}

void	Form::beSigned( Bureaucrat const & Bureaucrat ) {

	Bureaucrat.signForm(*this);
	if (Bureaucrat.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	this->_is_signed = true;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Form const& Copy)
{
	std::string signature = Copy.getIsSigned() ? "This form is signed." : "This form is not signed.";

	stream << Copy.getName() 
		<< " with signing grade " << Copy.getSignGrade() 
		<< " and execution grade " << Copy.getExecGrade() << ". "
		<< signature;
	return (stream);
}