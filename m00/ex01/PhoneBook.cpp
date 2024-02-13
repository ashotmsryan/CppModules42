#include "PhoneBook.hpp"

void	PhoneBook::setter(Contact neww, int i){cont[i] = neww;}
Contact	PhoneBook::getter(int i){return (cont[i]);}


bool check_data(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == 32)
			return (0);
		if (isalpha(str[i]) == 0)
			return (1);
	}
	return (0);
}

bool check_nmb(std::string str)
{
	if (str.find_first_of("0123456789", 0) < std::string::npos)
		return (1);
	return (0);
}

int	PhoneBook::add_new(PhoneBook *pb, int i)
{
	Contact neww;
	std::string ash;

	if (i == 8)
		i = 0;
	for(int j = 0; j < 5; j++)
	{
		std::cout << std::endl;
		if (j == 0)
		{
			std::cout << "Please insert the first name of contact -> ";
			getline(std::cin, ash);
			std::cin.clear();
			if (!ash[0] || check_data(ash))
				break ;
			neww.set_name(ash);
		}
		else if (j == 1)
		{
			std::cout << "Please insert the last name of contact -> ";
			getline(std::cin, ash);
			std::cin.clear();
			if (!ash[0] || check_data(ash))
				break ;
			neww.set_last_name(ash);
		}
		else if (j == 2)
		{
			std::cout << "Please insert the nickname of contact -> ";
			getline(std::cin, ash);
			std::cin.clear();
			if (!ash[0] || ash == "")
				break ;
			neww.set_nickname(ash);
		}
		else if (j == 3)
		{
			std::cout << "Please insert the phone number of contact -> ";
			getline(std::cin, ash);
			std::cin.clear();
			if (!ash[0] || !check_nmb(ash))
				break ;
			neww.set_number(ash);
		}
		else if (j == 4)
		{
			std::cout << "Please insert the secret of contact -> ";
			getline(std::cin, ash);
			std::cin.clear();
			if (!ash[0] || check_data(ash))
				break ;
			neww.set_secret(ash);
			pb->setter(neww, i);
			i++;
		}

	}
	return (i);
}

void	PhoneBook::find_cont(PhoneBook *pb, int i)
{
	Contact tmp;
	int		index;
	std::string str;
	std::string forS;

	std::cout <<  std::right << std::setw(10) << "index" << "|";
	std::cout <<  std::right << std::setw(10) << "first name" << "|";
	std::cout <<  std::right << std::setw(10) << "last name" << "|";
	std::cout <<  std::right << std::setw(10) << "nickname" << "|" << std::endl;
	for (int j = 0; j < i; j++)
	{
		tmp = pb->getter(j);
		std::cout <<  std::right << std::setw(10) << j << "|";
		forS = tmp.sett(0).substr(0, 9);
		if (tmp.sett(0).size() > 9)
			forS.push_back('.');
		std::cout <<  std::right << std::setw(10) << forS << "|";
		forS = tmp.sett(1).substr(0, 9);
		if (tmp.sett(1).size() > 9)
			forS.push_back('.');
		std::cout <<  std::right << std::setw(10) << forS << "|";
		forS = tmp.sett(2).substr(0, 9);
		if (tmp.sett(2).size() > 9)
			forS.push_back('.');
		std::cout <<  std::right << std::setw(10) << forS << "|" << std::endl;
	}
	std::string a;
	std::cout << "Please, insert the contact index, which you search for -> ";
	getline(std::cin, a);
	try{
		index = stoi(a);
	}
	catch(...)
	{
		std::cout << "As I remember we count by numbers!!!" << std::endl;
		std::cin.clear();
		// std::cin.ignore();
		std::cout.clear();
		return ;

	}
	std::cin.clear();
	std::cout.clear();
	// std::cin.ignore();
	if ((index < 0 || index > 7) || (index >= i && index <= 7))
	{
		std::cout << "The contact under the index is empty!" << std::endl;
		return ;
	}
	tmp = pb->getter(index);
	std::cout << "The index is [" << index << "]" << std::endl;
	std::cout << "The first name is [" << tmp.sett(0) << "]" << std::endl;
	std::cout << "The last name is [" << tmp.sett(1) << "]" << std::endl;
	std::cout << "The nickname is [" << tmp.sett(2) << "]" << std::endl;
	std::cout << "The phonenumber is [" << tmp.sett(3) << "]" << std::endl;
	std::cout << "The darkest secret [" << tmp.sett(4) << "]" << std::endl;
}