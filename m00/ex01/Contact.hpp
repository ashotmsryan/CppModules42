#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include  <locale>

class Contact
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_nmb;
	std::string	secret;

public:
	std::string sett(int i);
	//setters 
	void set_name(std::string s);
	void set_last_name(std::string s);
	void set_nickname(std::string s);
	void set_number(std::string s);
	void set_secret(std::string s);
	bool pars_input(std::string str);
};

#endif