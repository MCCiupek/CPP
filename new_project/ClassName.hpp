#ifndef __CLASSNAME_H__
# define __CLASSNAME_H__

# include <iostream>

// ************************************************************************** //
//                              ClassName Class                               //
// ************************************************************************** //


class ClassName {

	public:

		ClassName();
		ClassName( std::string name );
		ClassName( ClassName const &Copy );
		~ClassName();

		ClassName &	operator = ( const ClassName & toCopy );

		std::string	const & getName( void ) const ;
		void    			setName( std::string name ) ;

	private:

		std::string		_name;

};

std::ostream&	operator<<(std::ostream& stream, ClassName const& ClassName);

#endif /* __CLASSNAME_H__ */