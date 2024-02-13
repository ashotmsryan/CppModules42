#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	start_time = 0;
	end_time = 0;
	size = 0;
	point = 16;
}
PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	this->list = other.list;
	this->vec = other.vec;
	this->start_time = other.start_time;
	this->end_time = other.end_time;
	this->size = other.size;
	this->point = other.point;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		this->list = other.list;
		this->vec = other.vec;
		this->start_time = other.start_time;
		this->end_time = other.end_time;
		this->size = other.size;
		this->point = other.point;
	}
	return (*this);
}
/////////////////////////////////////////////////////////////

std::list<int> &PmergeMe::getList(){return (this->list);}
std::vector<int> &PmergeMe::getVector(){return (this->vec);}
size_t	PmergeMe::getStartTime(){return (this->start_time);}
size_t	PmergeMe::getEndTime(){return (this->end_time);}
size_t	PmergeMe::getSize(){return (this->size);}

void	PmergeMe::setList(long int n){this->list.push_back(n);}
void	PmergeMe::setVector(long int n){this->vec.push_back(n);}

void	PmergeMe::emptyy()
{
	if (!list.empty())
		list.clear();
	if (!vec.empty())
		vec.clear();
}


bool	PmergeMe::rangeValid(std::string nmb)
{
	int n = atoi(nmb.c_str());

	int i = 0;
	while (nmb[i] && (nmb[i] == '+' || nmb[i] == '-' || nmb[i] == '0'))
		i++;
	std::string s = std::to_string(n);
	if(s == &nmb[i])
		return (false);
	return (true);
}

//0->return (vector)  1->list  2->vector
std::vector<std::string> PmergeMe::getValuse(char **argv, int argc, int flag)
{
	std::vector<std::string> n;
	switch (flag)
	{
	case 0:
		for (size_t i = 1; i < static_cast<size_t>(argc); i++)
		{
			std::string	s = argv[i];
			std::stringstream ss(s);
			std::string token;

			while(ss >> token)
				n.push_back(token);
		}
		break;
	case 1:
		for (size_t i = 1; i < static_cast<size_t>(argc); i++)
		{
			std::string	s = argv[i];
			std::stringstream ss(s);
			std::string token;
			while(ss >> token)
				list.push_back(atoi(token.c_str()));
		}
		break;
	case 2:
		for (size_t i = 1; i < static_cast<size_t>(argc); i++)
		{
			std::string	s = argv[i];
			std::stringstream ss(s);
			std::string token;

			while(ss >> token)
				vec.push_back(atoi(token.c_str()));
		}
		break;
	}
	return (n);
}

bool	PmergeMe::validation(int argc, char **argv)
{
	std::vector<std::string> n;
	n = getValuse(argv, argc, 0);

	for (std::vector<std::string>::iterator itr = n.begin(); itr != n.end(); itr++)
	{
		size_t j = -1;
		while ((*itr)[++j])
		{
			if ((!isdigit((*itr)[j]) && ((*itr)[j] != '+'))
				|| ((*itr)[j] == '+' && (*itr)[j + 1] && !isdigit((*itr)[j + 1])))
			{
				std::cout << "Wrong argument input" << std::endl;
				n.clear();
				return (true);
			}
			if (j > 0 && (*itr)[j] && (*itr)[j] == '+' && (!isdigit((*itr)[j - 1]) || j + 1 == (*itr).size()))
			{
				std::cout << "Wrong argument input" << std::endl;
				n.clear();
				return (true);
			}
		}
		if (rangeValid(*itr))
		{
			std::cout << "out of range" << std::endl;
			n.clear();
			return (true);
		}
	}
	this->size = n.size();
	return (false);
}


void	PmergeMe::getTime(int flag)//flag == 1 -> start_time   flag == 2 -> end_time
{
	struct timeval result;

	gettimeofday(&result, 0);
	result.tv_sec = result.tv_sec * 1000000;
	if (flag == 1)
		this->start_time = result.tv_sec + result.tv_usec;
	else if(flag == 2)
		this->end_time = result.tv_sec + result.tv_usec;
}

void	PmergeMe::merge(std::vector<int>::iterator f, std::list<int>::iterator ff, int size, int flag)
{
	switch (flag)
	{
	case 1:
		if (size > this->point)
		{
			int n = (size / 2) + (size % 2);
			merge(f, ff, n, 1);
			merge(f + n, ff, size - n, 1);
			mergeVec(f, size);
		}
		else
			insertionVec(f, size);
		break;
	case 2:
		if (size > this->point)
		{
			int n = (size / 2) + (size % 2);
			merge(f, ff, n, 2);
			merge(f, incrDecr(ff, n, 2), size - n, 2);
			mergeList(ff, size);
		}
		else
			insertionList(ff, size);
		break;
	}
}
//////////////ALG VEC	

void	PmergeMe::mergeVec(std::vector<int>::iterator f, int size)
{
	std::vector<int>	neww;
	int n = (size / 2) + (size % 2);
	std::vector<int>::iterator it = f;
	std::vector<int>::iterator i = f + n;
	std::vector<int>::iterator j = f + n;
	std::vector<int>::iterator k = f + size;

	while (f != i && j != k)
	{
		if (*f >= *j)
		{
			neww.push_back(*j);
			j++;
		}
		else
		{
			neww.push_back(*f);
			f++;
		}
	}
	while (f != i)
	{
		neww.push_back(*f);
		f++;
	}
	while (j != k)
	{
		neww.push_back(*j);
		j++;
	}
	for (std::vector<int>::iterator itr = neww.begin(); itr != neww.end(); itr++)
	{
		*it = *itr;
		it++;
	}
}

void	PmergeMe::insertionVec(std::vector<int>::iterator f, int size)
{
	std::vector<int>::iterator a = f;
	std::vector<int>::iterator l = f;
	for (;f != (a + (size)); f++)
	{
		l = f;
		if (f != a && *(f - 1) > *f)
		{
			while(l != a && *l < *(l - 1))
			{
				int s = *(l - 1);
				*(l - 1) = *l;
				*l = s;
				l--;
			}
		}
	}
}


//////////////ALG LIST

void	PmergeMe::mergeList(std::list<int>::iterator ff, int size)
{
	int n = (size / 2) + (size % 2);
	std::list<int>	neww;
	std::list<int>::iterator it = ff;
	std::list<int>::iterator i = incrDecr(ff, n, 2);
	std::list<int>::iterator j = incrDecr(ff, n, 2);
	std::list<int>::iterator k = incrDecr(ff, size, 2);

	while (ff != i && j != k)
	{
		if (*ff >= *j)
		{
			neww.push_back(*j);
			j++;
		}
		else
		{
			neww.push_back(*ff);
			ff++;
		}
	}
	while (ff != i)
	{
		neww.push_back(*ff);
		ff++;
	}
	while (j != k)
	{
		neww.push_back(*j);
		j++;
	}
	for (std::list<int>::iterator itr = neww.begin(); itr != neww.end(); itr++)
	{
		*it = *itr;
		it++;
	}
	neww.clear();
}

std::list<int>::iterator PmergeMe::incrDecr(std::list<int>::iterator a, int size, int flag)
{
	if (flag == 1)
		while (size--)
			a--;
	else if (flag == 2)
		while (size--)
			a++;
	return (a);
}

void	PmergeMe::insertionList(std::list<int>::iterator ff, int size)
{
	std::list<int>::iterator a = ff;
	std::list<int>::iterator l = ff;

	for (;ff != incrDecr(a, size, 2); ff++)
	{
		l = ff;
		if (ff != a && *(incrDecr(ff, 1, 1)) > *ff)
		{
			while(l != a && *l < *(incrDecr(l, 1, 1)))
			{
				int s = *incrDecr(l, 1, 1);
				*incrDecr(l, 1, 1) = *l;
				*l = s;
				l--;
			}
		}
	}
}