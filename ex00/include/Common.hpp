#ifndef COMMON_HPP
#define COMMON_HPP

template <typename T>
void	swap(T& value1, T& value2)
{
	const T	tmp = value2;

	value2 = value1;
	value1 = tmp;
};

template <typename T>
T	min(const T& value1, const T& value2)
{
	return value2 <= value1 ? value2 : value1;
}

template <typename T>
T	max(const T& value1, const T& value2)
{
	return value2 >= value1 ? value2 : value1;
}

#endif
