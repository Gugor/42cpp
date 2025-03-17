#ifndef ARRAY_H 
# define ARRAY_H 

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array<T> &other);
		Array &operator=(const Array<T> &array);
		~Array(void);
		T &operator[](unsigned int n);
		const T &operator[](unsigned int index) const;
		unsigned int Size(void) const;
		T *Clone(void) const;

		class OutOfBoundsException : public std::exception
		{
			virtual const char *what(void) throw();
		};

	private:
		unsigned int _n;
		T	*_ptr;


};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array);
# include "Array.tpp"

#endif

