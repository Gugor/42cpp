#include "Whatever.hpp"

template <typename T>
Whatever<T>::Whatever(void)
{
	std::cout << ":: Whatever has been created." << std::endl; 
}

template <typename T>
Whatever<T>::Whatever(const Whatever &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
	}
	std::cout << ":: Whatever has been deep copied." << std::endl; 
}

template <typename T>
Whatever<T> &Whatever<T>::operator=(const Whatever &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
	}
	std::cout << ":: Whatever has been deep assigned." << std::endl; 
	return (*this);
}

template <typename T>
Whatever<T>::~Whatever(void){}

template <typename T>
void Whatever<T>::swap(T a, T b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T Whatever<T>::min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T Whatever<T>::max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
}
