#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	try
	{
		// sp.addNumber(1);
		// sp.addNumber(1);
		// sp.addNumber(1);
		// sp.addNumber(1);
		// sp.addNumber(1);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(-10);
		sp.addNumber(-20);
		
	}
	catch(std::out_of_range &n)
	{
		std::cerr << n.what() << std::endl; 
	};
	Span s(sp);

	std::cout << "the longest is for s " << sp.longestSpan() << std::endl;
	std::cout << "the shortest is for s " << sp.shortestSpan() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "the longest is sp " << sp.longestSpan() << std::endl;
	std::cout << "the shortest is sp " << sp.shortestSpan() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	sp.fullFill();
	std::cout << "the shortest is " << sp.shortestSpan() << std::endl;
	std::cout << "the longest is " << sp.longestSpan() << std::endl;
	return (0);
}