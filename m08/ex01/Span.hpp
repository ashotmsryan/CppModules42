#pragma once

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	std::vector<int>nmb;
	size_t			maxSize;
public:
	Span();
	Span(unsigned int N);
	Span(Span const &other);
	~Span();
	Span &operator=(Span const &other);


	void	addNumber(int neww);
	int		shortestSpan();
	int		longestSpan();

	void	fullFill();
};
