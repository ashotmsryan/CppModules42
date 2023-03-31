#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(DiamondTrap &other);
	~DiamondTrap();
	DiamondTrap &operator =(DiamondTrap &other);
	
	using ScavTrap::attack;

	void whoAmI();
};

#endif
