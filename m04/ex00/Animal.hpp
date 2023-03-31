#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &other);
	const Animal &operator =(const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const;
	virtual void setter(const std::string type);
	virtual std::string getType() const;
};

#endif