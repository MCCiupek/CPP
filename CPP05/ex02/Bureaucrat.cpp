#include "Bureaucrat.hpp"
#include <exception>

/* CONSTRUCTORS, DESTRUCTORS */

Bureaucrat::Bureaucrat( void ) : _grade(MIN_GRADE) {

	return;
}

Bureaucrat::Bureaucrat( const std::string name, unsigned int grade ) : 
	_name(name) {

	checkGrade(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &Copy ) : 
	_name(Copy.getName()), _grade(Copy.getGrade()) {

	checkGrade(this->_grade);
	return;
}

Bureaucrat::~Bureaucrat( void ) {

	return;
}

/* ASSIGNATION OPERATOR */

Bureaucrat & Bureaucrat::operator= (const Bureaucrat &Copy ) {

	if (this != &Copy)
		*this = Bureaucrat(Copy);
	return *this;
}

/* GETTERS, SETTERS */

std::string	const & Bureaucrat::getName( void ) const {

	return (this->_name);
}

unsigned int	Bureaucrat::getGrade( void ) const {

	return (this->_grade);
}

/* PUBLIC METHODS */

void	Bureaucrat::checkGrade( int grade ) {

	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

void 	Bureaucrat::incGrade( unsigned int i ) {

	std::cout << "Increasing " << this->getName() << "'s grade [" << this->getGrade() << "] by " << i << std::endl;
	checkGrade(this->_grade - i);
	this->_grade -= i;
	return;
}

void 	Bureaucrat::decGrade( unsigned int i ) {

	std::cout << "Decreasing " << this->getName() << "'s grade [" << this->getGrade() << "] by " << i << std::endl;
	checkGrade(this->_grade + i);
	this->_grade += i;
	return;
}

void	Bureaucrat::signForm( Form const & Form ) const {

	if (this->getGrade() > Form.getSignGrade())
		std::cout << *this << " cannot sign " << Form.getName() << " because his grade is too low." << std::endl;
	else
		std::cout << *this << " signs " << Form.getName() << "." << std::endl;
	return ;
}

void	Bureaucrat::executeForm( Form const & Form ) {

	if (!Form.getIsSigned())
		std::cout << *this << " cannot execute " << Form << " because it has not been signed.";
	else if (Form.execute(*this))
		std::cout << *this << " has executed " << Form << std::endl;
	else
		std::cout << *this << " has failed executing " << Form << std::endl;
	return ;
}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const& Copy)
{
	stream << Copy.getName() << ", bureaucrat grade " << Copy.getGrade();
	return (stream);
}
