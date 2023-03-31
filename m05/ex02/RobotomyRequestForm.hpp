#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	std::string	target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm &other);
	RobotomyRequestForm(std::string tg);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm &other);


	std::string getTarget()const;
	void	execute(Bureaucrat const & executor) const;
};

#endif
