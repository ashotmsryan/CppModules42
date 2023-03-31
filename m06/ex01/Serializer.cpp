#include "Serializer.hpp"

Serializer::Serializer(){};
Serializer::Serializer(Serializer &other){(void)(other);}
Serializer &Serializer::operator=(Serializer &other){return(other);}
Serializer::~Serializer(){};


uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	ret = reinterpret_cast<uintptr_t>(ptr);
	return(ret);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *ret = reinterpret_cast<Data *>(raw);
	return (ret);
}