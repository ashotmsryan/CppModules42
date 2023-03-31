#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	Brain	*mozg;
protected:
	std::string	type;
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	const Dog &operator =(const Dog &other);
	void makeSound() const;
	void setter(const std::string type);
	std::string getType() const;
};

#endif