#include "Serializer.hpp"

int main()
{
	Data *a = new(Data);

	std::cout << a << std::endl;
	uintptr_t	nmb = Serializer::serialize(a);
	std::cout << nmb << std::endl;

	std::cout << nmb << std::endl;
	Data	*b = Serializer::deserialize(nmb);
	std::cout << b << std::endl;
	delete b;
}