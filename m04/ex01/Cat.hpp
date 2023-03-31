#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	Brain	*mozg;
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