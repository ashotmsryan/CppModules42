#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *davo[6];
	
	for(int i = 0; i != 6; i++)
	{
		if (i < 3)
			davo[i] = new Cat();
		else	
			davo[i] = new Dog();
		davo[i]->makeSound();
	}
	for(int i = 0; i != 6; i++)
		delete davo[i];
	return 0;
}