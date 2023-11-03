#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "gtest/gtest-spi.h"

#include "Common.hpp"

template<typename T>
void	_swapTest(T v1, T v2)
{
	const T	expect1 = v1;
	const T	expect2 = v2;

	::swap(v1, v2);
	if (v1 == expect2 && v2 == expect1)
		SUCCEED();
	else
		FAIL() << "swap failed\n";
}

TEST(Common_test, swapChar) {

	const int	max = 127;

	for (int i = 0; i < max; i++)
	{
		char	v1 = i;
		char	v2 = max - i;
		_swapTest(v1, v2);
	}
}

TEST(Common_test, swapInt) {

	const int	max = 100;

	for (int i = -100; i < max; i++)
	{
		int	v1 = i;
		int	v2 = max - i;
		_swapTest(v1, v2);
	}
}

TEST(Common_test, swapFloat) {

	const int	max = 100;

	float	v1 = -10.0f;
	float	v2 = static_cast<float>(max);

	for (int i = -100; i < max; i++)
	{
		v1 += 0.4f;
		v2 -= static_cast<float>(max) - 0.3f;
		_swapTest(v1, v2);
	}
}

TEST(Common_test, swapDouble) {

	const int	max = 100;
	double	v1 = -10.0;
	double	v2 = static_cast<double>(max);

	for (int i = -100; i < max; i++)
	{
		v1 += 0.4;
		v2 -= static_cast<double>(max) - 0.3;
		_swapTest(v1, v2);
	}
}

template <typename T>
void	_minTest(T v1, T v2)
{
	const T	expect = v2 <= v1 ? v2 : v1;
	const T	actual = ::min(v1, v2);
	if (actual == expect)
		SUCCEED();
	else
		FAIL() << "min failed";
}

TEST(Common_test, minChar) {

	const int	max = 127;

	for (int i = 0; i < max; i++)
	{
		char	v1 = i;
		char	v2 = max - i;
		_minTest(v1, v2);
	}
}

TEST(Common_test, minInt) {

	const int	max = 100;

	for (int i = -100; i < max; i++)
	{
		int	v1 = i;
		int	v2 = max - i;
		_minTest(v1, v2);
	}
}

template <typename T>
void	_maxTest(T v1, T v2)
{
	const T	expect = v2 >= v1 ? v2 : v1;
	const T	actual = ::max(v1, v2);
	if (actual == expect)
		SUCCEED();
	else
		FAIL() << "max failed";
}

TEST(Common_test, maxInt) {
	const int	max = 127;

	for (int i = 0; i < max; i++)
	{
		char	v1 = i;
		char	v2 = max - i;
		_minTest(v1, v2);
	}
}
