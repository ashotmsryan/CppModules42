#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN		data;
		if (!data.checkValidationAndInsert(argv) || data.getNumber().size() != 1
			|| data.getNumber().empty())
			std::cout << "Error" << std::endl;
		else
			std::cout << data.getNumber().top() << std::endl;
		std::stack<double>().swap(data.getNumber());
	}
	else
		std::cout << "Wrong quantity of arguments! --->>>TRY WITH ONE ARGUMENT" << std::endl;
}
