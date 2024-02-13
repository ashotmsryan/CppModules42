#include "Harl.hpp"

void	Harl::debug(){std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;}
void	Harl::info(){std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;}
void	Harl::warning(){std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month.\n" << std::endl;}
void	Harl::error(){std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;}

void	Harl::complain(std::string level)
{
	int i = -1;

	void(Harl::*funcptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (++i != 4 && names[i] != level);
	switch (i)
	{
		case 0:
			(this->*funcptr[i])();
			// Intentional fallthrough
		case 1:
			(this->*funcptr[i])();
			// Intentional fallthrough
		case 2:
			(this->*funcptr[i])();
			// Intentional fallthrough
		case 3:
			(this->*funcptr[i])();
			break;
	}
}
