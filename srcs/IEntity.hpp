#ifndef IENTITY_HPP
# define IENTITY_HPP
class IEntity
{
	private :

	public :
		IEntity( void );
		IEntity( IEntity const & src );
		~IEntity( void );

		IEntity & operator=( IEntity const & rhs);
};
#endif
