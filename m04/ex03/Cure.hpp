#pragma once

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();

	Cure(Cure &other);
	Cure &operator=(Cure &other);
	Cure(std::string const &type);
	
	virtual AMateria *clone() const;
	void	use(ICharacter &target);
};

