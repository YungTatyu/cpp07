#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T	*_array;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array<T>&	operator=(const Array<T>& other);
	T&	operator[](unsigned int index) const;
	virtual ~Array();
	unsigned int	size() const;
};

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other)
{
	operator=(other);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] _array;
		this->_array = new T[other.size()];
		this->_size = other.size();
		for (unsigned int i = 0; i < other.size(); i++)
			(*this)[i] = other[i];
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](const unsigned int index) const
{
	if (index >= this->size())
	{
		throw std::out_of_range("Index out of range in Array::operator[]");
	}
	return _array[index];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

#endif
