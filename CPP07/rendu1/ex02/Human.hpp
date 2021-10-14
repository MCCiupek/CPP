#ifndef __HUMAN_H__
# define __HUMAN_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                                Human Class                                //
// ************************************************************************** //

class Human {

public:

	Human( void ) : _name("bob") {};
	Human( std::string name ) : _name(name) {};
	~Human( void ) {};

	std::string	getName( void ) const { return this->_name; };
	void		setName( std::string name ) { this->_name = name; };

private:

	std::string	_name;

};

#endif /* __HUMAN_H__ */
