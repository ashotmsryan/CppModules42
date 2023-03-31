#include "Harl.hpp"

void	Harl::debug(){std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;}
void	Harl::info(){std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;}
void	Harl::warning(){std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;}
void	Harl::error(){std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now." << std::endl;}

void	Harl::complain(std::string level)
{
	int i = -1;

	while (++i != 4 && level.compare("DEBUG") && level.compare("INFO") && level.compare("WARNING") && level.compare("ERROR"));
	switch (i)
	{
		case 0:
			this->debug();	
		break;
		case 1:
			this->info();	
		break;
		case 2:
			this->warning();	
		break;
		case 3:
			this->error();	
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
