#include "Contact.hpp"

std::string Contact::sett(int i)
{
	if (i == 0)
		return (first_name);
	else if (i == 1)
		return (last_name);
	else if (i == 2)
		return (nickname);
	else if (i == 3)
		return (phone_nmb);
	return (secret);
}

void Contact::set_name(std::string s){this->first_name = s;}
void Contact::set_last_name(std::string s){this->last_name = s;}
void Contact::set_nickname(std::string s){this->nickname = s;}
void Contact::set_number(std::string s){this->phone_nmb = s;}
void Contact::set_secret(std::string s){this->secret = s;}

