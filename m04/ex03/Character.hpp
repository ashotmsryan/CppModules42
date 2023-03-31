#pragma once

# include "ICharacter.hpp"

class Character : public ICharacter
{
	std::string name;
	AMateria *arr[4];
public:
	Character();
	Character(Character &other);
	Character(std::string name);
	Character &operator=(Character &other);
	~Character();


	std::string const &getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
