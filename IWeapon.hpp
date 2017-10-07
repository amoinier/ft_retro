#ifndef IWEAPON_HPP
# define IWEAPON_HPP
class IWeapon
{
	private :

	public :
		IWeapon( void );
		IWeapon( IWeapon const & src );
		~IWeapon( void );

		IWeapon & operator=( IWeapon const & rhs);
};
#endif
