#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void	iter(T *array, size_t size, void (*func)(T&))
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template <typename T>
void	iter(const T *array, size_t size, void (*func)(const T&))
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

#endif
