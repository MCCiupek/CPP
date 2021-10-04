#ifndef __HUMAN_H__
# define __HUMAN_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                                Human Class                                //
// ************************************************************************** //

class Human {

public:

	Human( void ) : _name("bob"), _age(0) {};
	Human( std::string name, int age ) : _name(name), _age(age) {};
	~Human( void ) {};

	//bool 		operator>(Human const& other) const { return _age > other._age; };
    //bool 		operator<(Human const& other) const { return _age < other._age; };

	std::string	getName( void ) const { return this->_name; };
	void		setName( std::string name ) { this->_name = name; };

	int			getAge( void ) const { return this->_age; };
	void		setAge( int age ) { this->_age = age; };

private:

	std::string	_name;
	int			_age;

};

std::ostream&	operator<<(std::ostream& stream, Human const& Human) {

	stream << Human.getName() << ", " << Human.getAge() << " years old";
	return stream;
};

#endif /* __HUMAN_H__ */
