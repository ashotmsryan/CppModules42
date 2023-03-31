#pragma once

#include <iostream>
#include "Data.hpp"
struct Data;

class Serializer
{
	Serializer();
	Serializer(Serializer &other);
	Serializer &operator=(Serializer &other);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
