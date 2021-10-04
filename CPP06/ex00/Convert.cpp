#include "Convert.hpp"
#include <limits>

/* UTILS */

void  trim_spaces( string & str ) {

	while (std::isspace(str[0]))
		if (str.length() > 1) { str.erase(0, 1); } else { break ; }
	while (std::isspace(str[str.length() - 1]))
		if (str.length() > 1) { str.erase(str.length() - 1, 1); } else { break ; }
}

bool    is_inf_or_nan( string str ) {
	return (!str.compare("+inf") || !str.compare("-inf") || !str.compare("inf") || 
		!str.compare("+inff") || !str.compare("-inff") || !str.compare("inff") || 
		!str.compare("+nan") || !str.compare("-nan") || !str.compare("nan") || 
		!str.compare("+nanf") || !str.compare("-nanf") || !str.compare("nanf"));
}

bool	is_digit( string str ) {

	string	front_chars = "+-0123456789.";
	string	mid_chars = "0123456789.";
	string	back_chars = "0123456789f";

	if (front_chars.find(str[0]) == str.npos)
		return false;
	for (unsigned long i = 1; i < str.length() - 1; i++)
		if (mid_chars.find(str[i]) == str.npos)
			return false;
	if (back_chars.find(str[str.length() - 1]) == str.npos)
		return false;
	return true;
}

bool	is_null( string str ) {

	string	front_chars = "+-0.";
	string	mid_chars = "0.";
	string	back_chars = "0f";

	if (front_chars.find(str[0]) == str.npos)
		return false;
	for (unsigned long i = 1; i < str.length() - 1; i++)
		if (mid_chars.find(str[i]) == str.npos)
			return false;
	if (back_chars.find(str[str.length() - 1]) == str.npos)
		return false;
	return true;
}

/* PRIVATE METHODS */

bool	Convert::checkFormat( void ) {

	return (!is_digit(_str) ||
		(_str.find('.') != _str.npos && _str.find('.') != _str.rfind('.')) ||
		(_str.find('+') != _str.npos && _str.rfind('+') != 0) ||
		(_str.find('-') != _str.npos && _str.rfind('-') != 0) ||
		(_str.find('f') != _str.npos && _str.find('f') != _str.length() - 1) ||
		(!_input && !is_null(_str)));
}

void	Convert::setType( void ) {

	trim_spaces(_str);
	if (_str.length() == 1 && !isdigit(_str[0]))
	{
		_type = CHAR1;
		return ;
	}
	if (!is_inf_or_nan(_str) && this->checkFormat())
	{
		_type = NA;
		return ;
	}
	if (_str.find('f') != _str.npos)
		_type = FLOAT;
	if (is_inf_or_nan(_str) || _str.find('f') == _str.npos)
		_type = DBL;
	if (_input >= MY_INT_MIN && _input <= MY_INT_MAX)
		_type = INT;
	if (_input >= MY_CHAR_MIN && _input <= MY_CHAR_MAX)
		_type = CHAR3;
	if (_input >= PRINT_CHAR_MIN && _input <= PRINT_CHAR_MAX)
		_type = CHAR2;
}

/* PUBLIC METHODS */

void	Convert::printChar( ostream& stream ) const {

	if (_type > CHAR3)
		stream << "char: impossible" << endl;
	else if (_type > CHAR2)
		stream << "char: Non displayable" << endl;
	else if (_type > CHAR1)
		stream << "char: '" << static_cast<char>(this->_input) << "'" << endl;
	else
		stream << "char: '" << _str[0] << "'" << endl;
}

void	Convert::printInt( ostream& stream ) const {

	if (_type > INT)
		stream << "int: impossible" << endl;
	else if (_type == CHAR1)
		stream << "int: " << static_cast<int>(this->_str[0]) << endl;
	else
		stream << "int: " << static_cast<int>(this->_input) << endl;
		
}

void	Convert::printDouble( ostream& stream ) const {

	if (_type > DBL || _input < -std::numeric_limits<double>::max() - 1 || _input > std::numeric_limits<double>::max())
		stream << "double: impossible" << endl;
	else if (_type == CHAR1)
		stream << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(this->_str[0]) << endl;
	else if (_input >= 1e+06)
		stream << "double: " << std::scientific << std::setprecision(1) << static_cast<double>(this->_input) << endl;
	else
		stream << "double: " << std::fixed << std::setprecision(1) << this->_input << endl;
}

void	Convert::printFloat( ostream& stream ) const {

	if (_type > FLOAT || _input < -std::numeric_limits<float>::max() - 1 || _input > std::numeric_limits<float>::max())
		stream << "float: impossible" << endl;
	else if (_type == CHAR1)
		stream << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(this->_str[0]) << "f" << endl;
	else
		stream << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(this->_input) << "f" << endl;
}

/* OPERATOR OVERLOAD */

ostream&	operator<<( ostream& stream, Convert const& Convert) {
	Convert.printChar(stream);
	Convert.printInt(stream);
	Convert.printFloat(stream);
	Convert.printDouble(stream);
	return stream;
}
