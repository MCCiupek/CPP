#ifndef __CONVERT_H__
# define __CONVERT_H__

# include <iostream>
# include <iomanip>
# include <stdlib.h>

# define MY_INT_MIN -2147483648
# define MY_INT_MAX 2147483647
# define MY_CHAR_MIN -128
# define MY_CHAR_MAX 127
# define PRINT_CHAR_MIN 32
# define PRINT_CHAR_MAX 126

using std::cout;
using std::endl;
using std::atof;
using std::string;
using std::ostream;
using std::isdigit;

// ************************************************************************** //
//                                Convert Class                               //
// ************************************************************************** //

enum TYPE { CHAR1, CHAR2, CHAR3, INT, DBL, FLOAT, NA };

class Convert {

	public:

		Convert() {};
		Convert( char input[] ) : _str(input), _input(atof(input)) { setType(); };
		Convert( Convert const &Copy ) { *this = Copy; };
		~Convert() {};

		Convert &	operator = ( const Convert & toCopy ) { this->_input = toCopy._input; return *this; };

		operator int() { return static_cast<int>(this->_input); }
		operator double() { return static_cast<double>(this->_input); }

		void	printFloat( ostream& stream ) const;
		void	printChar( ostream& stream ) const;
		void	printInt( ostream& stream ) const;
		void	printDouble( ostream& stream ) const;

	private:

		bool	checkFormat( void );
		void	setType( void );

		string		_str;
		float		_input;
		int			_type;

};

ostream&	operator<<( ostream& stream, Convert const& Convert );

#endif /* __CONVERT_H__ */