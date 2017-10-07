#ifndef MAP_HPP
# define MAP_HPP
class Map
{
	private :

	public :
		Map( void );
		Map( Map const & src );
		~Map( void );

		Map & operator=( Map const & rhs);
};
#endif
