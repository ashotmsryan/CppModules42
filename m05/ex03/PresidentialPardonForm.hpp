#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	std::string	target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string tg);
	PresidentialPardonForm(PresidentialPardonForm &other);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm &other);

	std::string getTarget();
	void	execute(Bureaucrat const & executor) const;
};

#endif
