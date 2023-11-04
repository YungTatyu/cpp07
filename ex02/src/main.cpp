#include "Array.hpp"
#include <iostream>

int	main()
{
	std::string	str[0];
	std::cout << str[0] << '\n';

	Array<std::string>	array;

	std::cout << array[0] << '\n';
	std::cout << array.size() << '\n';
	return 0;
}