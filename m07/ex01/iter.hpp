#pragma once

#include <iostream>

template <typename T>
void	iter(T *arr, size_t size, void(print)(T const &))
{
	for (size_t i = 0; i < size; i++)
		print(arr[i]);
}
