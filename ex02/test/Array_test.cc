#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "gtest/gtest-spi.h"

#include "Array.hpp"
#include <vector>

TEST(Array_test, operator) {
	std::vector<std::string>	v = {"thomas", "tachu", "yung", "what", "end"};
	const unsigned int	size = v.size();
	Array<std::string>	array(size);

	// operator = のテスト
	for (size_t i = 0; i < size; i++)
	{
		array[i] = v[i];
	}
	for (size_t i = 0; i < size; i++)
	{
		EXPECT_EQ(v[i], array[i]);
	}

	// 値の再代入のテスト
	for (size_t i = 0; i < size; i++)
	{
		i % 2 == 1 ? array[i] = std::string("new ") + v[i] : array[i] = "";
	}
	for (size_t i = 0; i < size; i++)
	{
		if (i % 2 == 1)
			EXPECT_EQ(std::string("new ") + v[i], array[i]);
		else
			EXPECT_EQ("", array[i]);
	}
}

TEST(Array_test, deepCopy) {
	std::vector<int>	v1 = {1, 2, 3};
	std::vector<int>	v2 = {5, 6, 7, 8, 10};
	Array<int>	array1(v1.size());
	Array<int>	array2(v2.size());

	// operator = のテスト
	for (size_t i = 0; i < array1.size(); i++)
	{
		array1[i] = v1[i];
	}
	for (size_t i = 0; i < array2.size(); i++)
	{
		array2[i] = v2[i];
	}

	Array<int>	tmp;
	tmp = array1;
	array1 = array2;
	array2 = tmp;
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << "v1=" << v1[i] << " array2=" << array2[i] << '\n';
		EXPECT_EQ(v1[i], array2[i]);
	}
	for (size_t i = 0; i < v2.size(); i++)
	{
		std::cout << "v2=" << v2[i] << " array1=" << array1[i] << '\n';
		EXPECT_EQ(v2[i], array1[i]);
	}
}


TEST(Array_test, exception) {

	Array<unsigned char>	array(3);

	EXPECT_THROW(
		{
			array[5];
		},
		std::out_of_range
	);

	EXPECT_NO_THROW(
		{
			array[2];
		}
	);
}
