#pragma once 

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <sys/time.h>

class PmergeMe
{
	std::list<int> list;
	std::vector<int> vec;

	int			point;
	size_t		start_time;
	size_t		end_time;
	size_t		size;
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);

	std::list<int> &getList();
	std::vector<int> &getVector();
	size_t	getStartTime();
	size_t	getEndTime();
	size_t	getSize();
	void	setVector(long int n);
	void	setList(long int n);
	void	getTime(int flag);
	std::vector<std::string> getValuse(char **argv, int argc, int flag);


	bool	validation(int argc, char **argv);
	bool	rangeValid(std::string nmb);

	void	merge(std::vector<int>::iterator f, std::list<int>::iterator ff, int size, int flag);
	
	void	mergeVec(std::vector<int>::iterator f, int n);
	void	insertionVec(std::vector<int>::iterator f, int size);
	
	void	mergeList(std::list<int>::iterator ff, int size);
	void	insertionList(std::list<int>::iterator f, int size);
	std::list<int>::iterator incrDecr(std::list<int>::iterator a, int size, int flag);

	void	emptyy();
};
