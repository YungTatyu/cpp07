#include "Array.hpp"
#include <iostream>

template <typename T>
void	_print(Array<T>& array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << '\n';
	}
}

// int	main()
// {
// 	std::string	str[0];
// 	std::cout << "value=" << str[0] << '\n';
// 	str[0] = "test";
// 	std::cout << "value=" << str[0] << '\n';
// 	int	ia[0];
// 	std::cout << "value=" << ia[0] << '\n';
// 	ia[0] = 3;
// 	std::cout << "value=" << ia[0] << '\n';

// 	Array<std::string>	array;

// 	try
// 	{
// 		std::cout << array[0] << '\n';
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << array.size() << '\n';

// 	Array<unsigned char>	charArray(3);

// 	charArray[0] = 'a';
// 	charArray[1] = 'b';
// 	charArray[2] = 'c';
// 	_print(charArray);

// 	charArray[1] = 'z';
// 	_print(charArray);
// 	Array<unsigned char>	emptyArray;
// 	emptyArray = charArray;
// 	// charArray = emptyArray;
// 	_print(emptyArray);
// 	emptyArray[0] = 's';
// 	emptyArray[2] = 'x';
// 	_print(emptyArray);
// 	_print(charArray);


// 	return 0;
// }
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}