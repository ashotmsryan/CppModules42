#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(time(nullptr));
	Base	*a;

	switch (std::rand() % 3)
	{
	case 0:
		a = new (A);
		break;
	case 1:
		a = new (B);
		break;
	case 2:
		a = new (C);
		break;
	}
	return (a);
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "The derived has type of A" << std::endl;
	else
	{
		B *b = dynamic_cast<B*>(p);
		if (b)
			std::cout << "The derived has type of B" << std::endl;
		else
		{
			C *c = dynamic_cast<C*>(p);
			if (c)
				std::cout << "The derived has type of C" << std::endl;
			else
				std::cout << "The derived has an other type" << std::endl;
		}
	}
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)(a);
		std::cout << "The derived has type of A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)(b);
			std::cout << "The derived has type of B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)(c);
				std::cout << "The derived has type of C" << std::endl;			
			}
			catch(const std::exception& e)
			{
				std::cout << "The derived has an other type" << std::endl;
			}
		}
	}
}

int main()
{
	Base *a = generate();

	identify(a);

	identify(&(*a));
	delete a;
}