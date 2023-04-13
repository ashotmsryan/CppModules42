#include "PmergeMe.hpp"

void	printAll(size_t vec, size_t list, PmergeMe &data, char **argv)
{
	std::cout << "Before: ";
	for (size_t i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (std::list<int>::iterator i = data.getList().begin(); i != data.getList().end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << data.getSize() << " elements with std::list : " << list << " us " <<std::endl; 
	std::cout << "Time to process a range of " << data.getSize() << " elements with std::vector : " << vec << " us " << std::endl; 
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		PmergeMe	data;
		size_t		for_list_t;
		size_t		for_vec_t;

		if (data.validation(argc, argv))
			return (1);
		data.getTime(1);
		data.getValuse(argv, argc, 1);
		data.merge(data.getVector().begin(),data.getList().begin(), data.getSize(), 2);
		data.getTime(2);
		for_list_t = data.getEndTime() - data.getStartTime();
		data.getTime(1);
		data.getValuse(argv, argc, 2);
		data.merge(data.getVector().begin(),data.getList().begin(), data.getSize(), 1);
		data.getTime(2);
		for_vec_t = data.getEndTime() - data.getStartTime();
		printAll(for_vec_t, for_list_t, data, argv);
		// for (std::list<int>::iterator f = data.getList().begin(); f != data.getList().end(); f++)
		// 	std::cout << *f << std::endl;
		data.emptyy();
	}
}