#ifndef __CAST_FLOAT_H__
# define __CAST_FLOAT_H__

# include <iostream>

using std::cout;
using std::endl;
using std::atof;
using std::string;

// ************************************************************************** //
//                              CastFloat Class                               //
// ************************************************************************** //


class CastFloat {

	public:

		CastFloat() {};
		CastFloat( char input[] ) : _str(input), _input(std::atof(input)) {};
		CastFloat( CastFloat const &Copy ) { *this = Copy; };
		~CastFloat() {};

		CastFloat &	operator = ( const CastFloat & toCopy ) { this->_input = toCopy._input; return *this; };

		operator int() { return static_cast<int>(this->_input); }
		operator double() { return static_cast<double>(this->_input); }

		void	printFloat( void ) const;
		void	printChar( void ) const;
		void	printInt( void ) const;
		void	printDouble( void ) const;

	private:

		string		_str;
		float		_input;

};

std::ostream&	operator<<(std::ostream& stream, CastFloat const& CastFloat);

void	CastFloat::printFloat( void ) const {

	cout << "float: " << this->_input << endl;
}

void	CastFloat::printChar( void ) const {

	int i = static_cast<int>(this->_str[0]);

	if (!isdigit(this->_str[0]) && this->_str.length() >= 3)
		cout << "char: impossible" << endl;
	else if (i < 32 || i >= 127)
		cout << "char: impossible" << endl;
	else
		cout << "char: " << static_cast<char>(i) << endl;
}

void	CastFloat::printInt( void ) const {

	int	i = this->_input;
	if (i)
		cout << "int: " << i << endl;
	else
		cout << "int: impossible" << endl;
}

void	CastFloat::printDouble( void ) const {

	double	n = this->_input;
	cout << "double: " << n << endl;
}

std::ostream&	operator<<(std::ostream& stream, CastFloat const& CastFloat) {
	stream << CastFloat.printChar()
			<< CastFloat.printInt()
			<< CastFloat.printDouble()
			<< CastFloat.printFloat()
}

#endif /* __CAST_FLOAT_H__ */