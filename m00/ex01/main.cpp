#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	std::string davo;
	int	i = 0;
	int count = 0;

	while (1)
	{
		davo.clear();
		std::cout << "Please insert command (EXIT, ADD, SEARCH) -> ";
		getline(std::cin, davo);
		if (std::cin.eof())
			break ;
		if (davo.compare("ADD") == 0)
		{
			i = pb.add_new(&pb, i);
			if (count < 8)
				count = i;
		}
		else if (davo.compare("SEARCH") == 0)
			pb.find_cont(&pb, count);
		else if (davo.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Wrong command input!" << std::endl;
	}
	return(0);
}