#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "gtest/gtest-spi.h"

#include "iter.hpp"

template <typename T>
void	_print(const T& value)
{
	std::cout << value << "\n";
}

TEST(iter_test, print) {

	std::string	array[] = {"this", "is", "test", "period"};

	testing::internal::CaptureStdout();
	iter(&array, sizeof(array) / sizeof(std::string), _print);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();

	EXPECT_EQ("this\nis\ntest\nperiod\n", stdoutOutput);
}

void	_increment(int& value)
{
	value++;
}

TEST(iter_test, increment) {

	int	array[] = {0, 1, 2, 3, 4, 5};
	const size_t	size = sizeof(array) / sizeof(int);
	int	expect[size];
	for (size_t i = 0; i < size; i++)
	{
		expect[i] = array[i] + 1;
	}

	iter(&array, size, _increment);
	for (size_t i = 0; i < size; i++)
	{
		EXPECT_EQ(expect[i], array[i]);
	}
}
