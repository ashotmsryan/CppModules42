#pragma once

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename A>
const A &min(const A &a, const A &b)
{
	return ((a < b) ? a : b);
}

template <typename B>
const B &max(const B &a, const B &b)
{
	return ((a > b) ? a : b);
}