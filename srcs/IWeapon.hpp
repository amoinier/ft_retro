#ifndef IWEAPON_HPP
# define IWEAPON_HPP
class IWeapon
{
	private :

	public :
		IWeapon( void );
		IWeapon( IWeapon const & src );
		virtual ~IWeapon( void ) = {};

		IWeapon & operator=( IWeapon const & rhs);
};
#endif
