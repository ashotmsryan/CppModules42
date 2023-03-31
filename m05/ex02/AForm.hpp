#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
#include <fstream>
class Bureaucrat;

class AForm
{
	const std::string name;
	const int 		grade;
	const int		grade_exe;
	bool			sign;
public:
	AForm();
	virtual ~AForm();
	AForm(std::string nm, int gd, int gd_exe);
	AForm(AForm &other);
	AForm &operator=(AForm &AForm);

	class GradeTooHighException : public std::exception
	{
		const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char	*what() const throw();
	};

	class CuldNotExec : public std::exception
	{
		const char	*what() const throw();
	};
	void	beSigned(Bureaucrat &ob);

	//getters
	virtual int		getGrade() const;
	virtual const	std::string getName() const;
	virtual int		getGradeExe() const;
	virtual bool	getSign() const;


	virtual void	execute(Bureaucrat const & executor) const = 0;

};

std::ostream &operator << (std::ostream &out, AForm &ob);

#endif