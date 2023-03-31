# include "iter.hpp"

void print(char a)
{
	std::cout << a << std::endl;
}

void print_nmb(int a)
{
	std::cout << a << std::endl;
}

int main()
{
	char a[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(a, 5, &print);

	int b[5] = {0, 1, 2, 3, 4};
	iter(b, 5, &print_nmb);
}