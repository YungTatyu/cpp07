#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "gtest/gtest-spi.h"

#include "Common.hpp"


template<typename T>
void	_swapTest(T value1, T value2)
{
	const T	expect1 = value1;
	const T	expect2 = value2;

	::swap(c1, c2);
	if (c1 == expect2 && c2 == expect1)
		SUCCEED();
	else
		FAIL() << "swap failed\n";
}

TEST(Common_test, swapChar) {

	const int	ASCII_NUM = 127;

	for (int i = 0; i < ASCII_NUM; i++)
	{
		char	c1 = i;
		char	c2 = ASCII_NUM - i;
		_swapTest(c1, c2);
	}
}
