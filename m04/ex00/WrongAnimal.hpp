#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	const WrongAnimal &operator =(const WrongAnimal &other);
	~WrongAnimal();
	void makeSound() const;
	void setter(const std::string type);
	std::string getType() const;
};

#endif
