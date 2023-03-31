#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern &other);
	Intern &operator= (Intern &other);
	~Intern();

	AForm *makeForm(std::string name, std::string target);

	class canNotMakeForm : public std::exception
	{
		const char *what() const throw();
	};

	AForm *makeShr(std::string target);
	AForm *makeRob(std::string target);
	AForm *makePre(std::string target);
};

#endif