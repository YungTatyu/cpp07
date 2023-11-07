
#include "iter.hpp"
#include <iostream>

template <typename T>
void	_print(const T& value)
{
	std::cout << value << "\n";
}

void	_reverseString(std::string& val) {
	std::reverse(val.begin(), val.end());
}

int	main()
{
	std::string	array[] = {
		"racecar", "Madam, in Eden I'm Adam",
		"Able was I, I saw elba",
		"Mr. Owl ate my metal worm",
		"Evil is a name of a foeman, as I live"
	};
	iter(array, sizeof(array) / sizeof(std::string), _reverseString);
	iter(array, sizeof(array) / sizeof(std::string), _print);

	return 0;
}