#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
class Animal;


class Cat : public Animal
{
protected:
	std::string	type;
public:
	Cat();
	~Cat();
	Cat(const Cat &other);
	const Cat &operator =(const Cat &other);
	void setter(const std::string type);
	std::string getType() const;
	void makeSound() const;
};

#endif