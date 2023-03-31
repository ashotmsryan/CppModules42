#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected:
	std::string	type;
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &other);
	const WrongCat &operator =(const WrongCat &other);
	void setter(const std::string type);
	std::string getType() const;
	void makeSound() const;
};

#endif
