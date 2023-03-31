#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &other);
	ScavTrap &operator =(ScavTrap &other);
	void	attack(const std::string &target);
	void	guardGate();
	virtual ~ScavTrap();
};

#endif