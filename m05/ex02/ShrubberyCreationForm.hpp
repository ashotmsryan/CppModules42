#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	std::string	target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string tg);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);


	std::string getTarget()const;
	void	execute(Bureaucrat const & executor) const;
};

#endif