#ifndef __KAREN_H__
# define __KAREN_H__

# include <iostream>
# include <string>

# define NUM_OPT 4

enum OPTIONS { DEBUG, INFO, WARNING, ERROR };

// ************************************************************************** //
//                                 Karen Class                                //
// ************************************************************************** //

class Karen {

	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		void (Karen::*f[NUM_OPT])( void );

	public:

		Karen( void );
		~Karen( void );

		void complain( std::string level );
		
};

#endif /* __KAREN_H__ */
