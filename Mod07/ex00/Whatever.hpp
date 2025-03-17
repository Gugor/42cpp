#ifndef WHATEVER_H 
# define WHATEVER_H 

# include <iostream>
# include <string>



template <typename T>
class Whatever
{
	public:
		Whatever(void);
		Whatever(const Whatever &other);
		Whatever &operator=(const Whatever<T> &whatever);
		~Whatever(void);

		static void swap(T &a, T &b);
		static T min(T a, T b);
		static T max(T a, T b);
};

# include "Whatever.tpp"
#endif

