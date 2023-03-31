#pragma once

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(Ice &other);
	Ice &operator=(Ice &other);
	Ice (std::string const &type);
	
	virtual AMateria *clone() const;
	void	use(ICharacter &target);
	
};
