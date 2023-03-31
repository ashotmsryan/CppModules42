#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	const std::string name;
	int		grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);
	~Bureaucrat();

	void increment();
	void decrement();


	class GradeTooHighException : public std::exception
	{
		const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char	*what() const throw();
	};

	std::string getName()const;
	int	getGrade() const;
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &ob);

#endif