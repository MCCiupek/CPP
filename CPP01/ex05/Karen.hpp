#ifndef __KAREN_H__
# define __KAREN_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                                  Messages                                  //
// ************************************************************************** //

# define NUM_OPT 4

enum OPTIONS { DEBUG, INFO, WARNING, ERROR };

// ************************************************************************** //
//                                 Karen Class                                //
// ************************************************************************** //

class Karen {

public:

	Karen( void );
	~Karen( void );

	void complain( std::string level );

private:

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	void (Karen::*f[NUM_OPT])( void );
	
	/*struct fptr
	{
		std::string key;
		void	(Karen::* f)( void );
	};*/
};

#endif /* __KAREN_H__ */
