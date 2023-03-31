#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	Contact cont[8];
public:
	void	setter(Contact neww, int i);
	Contact	getter(int i);
	int		add_new(PhoneBook *pb, int i);
	void	find_cont(PhoneBook *pb, int i);
};

#endif
