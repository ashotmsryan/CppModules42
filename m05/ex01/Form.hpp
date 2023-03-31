#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	const std::string name;
	const int 		grade;
	const int		grade_exe;
	bool			sign;
public:
	Form();
	~Form();
	Form(std::string nm, int gd, int gd_exe);
	Form(Form &other);
	Form &operator=(Form &Form);

	class GradeTooHighException : public std::exception
	{
		const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char	*what() const throw();
	};

	void	beSigned(Bureaucrat &ob);

	//getters
	int getGrade();
	const std::string getName();
	int getGradeExe();
	bool	getSign();
};

std::ostream &operator << (std::ostream &out, Form &ob);

#endif