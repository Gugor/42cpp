#ifndef EASYFIND_H 
# define EASYFIND_H 

# include <iostream>
# include <algorithm>
# include <iterator>

template<typename T_Container>
void easyfind(T_Container &cont, int indx)
{
	if (std::find(cont.begin(), cont.end(), indx) == cont.end())
		throw std::out_of_range("Item not found");
}	

#endif

