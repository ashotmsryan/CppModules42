#include "Span.hpp"

Span::Span()
{
	maxSize = 10;
	// std::cout << "default ctor called!" << std::endl;
}

Span::Span(unsigned int N)
{
	maxSize = N;
	// std::cout << "param ctor called!" << std::endl;
}

Span::Span(Span const &other)
{
	this->nmb = other.nmb;
	this->maxSize = other.maxSize;
	// std::cout << "copy ctor called!" << std::endl;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->nmb = other.nmb;
		this->maxSize = other.maxSize;
	}
	// std::cout << "assignment operator called!" << std::endl;
	return (*this);
}

Span::~Span()
{
	nmb.clear();
	// std::cout << "dtor called!" << std::endl;
}

////////////////////////////////////////////////////////////////////////

void	Span::addNumber(int neww)
{
	if (this->nmb.size() == this->maxSize)
		throw std::out_of_range("out of range!");
	else
		this->nmb.push_back(neww);
}

int		Span::shortestSpan()
{
	int min = INT_MAX;

	int size = this->nmb.size();
	if (size == 0)
		throw std::out_of_range("the size is 0!");
	std::vector<int>::iterator a = nmb.begin();
	std::vector<int>::iterator c = nmb.begin();
	std::vector<int>::iterator b = nmb.begin();
	for (int i = 0; i < size; i++)
	{
		b = c;
		for (int j = 0; j < size; j++)
		{
			if (min > abs(*a - *b) && a != b)
				min = abs(*a - *b);
			b++;
		}
		a++;
	}
	return (min);
}

int		Span::longestSpan()
{
	if (!nmb.size())
		throw std::out_of_range("the size is 0!");
	std::vector<int>::iterator a = std::min_element(nmb.begin(), nmb.end());
	std::vector<int>::iterator b = std::max_element(nmb.begin(), nmb.end());
	return (abs(*b - *a));
}

void	Span::fullFill()
{
	std::srand(time(NULL));
	for (size_t i = 0; i < maxSize; i++)
		nmb[i] = std::rand() % 100;
}