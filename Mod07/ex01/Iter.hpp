#ifndef ITER_H 
# define ITER_H 

#include <iostream> 

template <typename T> 
void iter(T arr[], size_t size, void (*fnc)(T &))
{
	size_t indx;
	
	indx = -1;
	while (arr[++indx] && indx < size)
		fnc(arr[indx]);
}

template <typename T>
void printTemp(T &s)
{
		std::cout << s;
}


template <typename T>
void toupper(T &c)
{
	if (c >= 97 && c <= 122)
		std::cout << static_cast<char>(c - 32); 
	else
		std::cout << static_cast<char>(c);
}
#endif

