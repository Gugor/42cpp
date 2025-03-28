#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
unsigned int Array<T>::Size(void) const
{
	return (this->_n);
}

template <typename T>
Array<T>::Array(void)
{
	this->_ptr = new T[0];
	this->_n = 0;
	std::cout << ":: Default array item created." << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_ptr = new T[n];
	this->_n = n;
	std::cout << ":: Array item created with size " << n << "." << std::endl;
}

template <typename T>
T *Array<T>::Clone(void) const
{
	T *newArr = new T[this->_n];
	unsigned int indx = 0;
	while (indx < this->_n)
	{
		newArr[indx] = this->_ptr[indx];
		indx++;
	}
	return (newArr);
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	if (this != &other)
	{
		this->_n = other.Size();
		this->_ptr = other.Clone();
		std::cout << ":: New array copied with size " << this->_n << " created." << std::endl;
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		if (this->_ptr)
			delete[] this->_ptr;
		this->_n = other.Size();
		this->_ptr = other.Clone();
		std::cout << ":: New array assigned with size " << this->_n << " created." << std::endl;
	}
	return (*this);
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array)
{
	T *tmp = array.Clone();
	unsigned int indx = 0;

	std::cout << "Array ["; 	
	while (indx < array.Size())
	{
		out << tmp[indx];
		if (indx != array.Size() - 1)
			out << ",";
		indx++;
	}
	std::cout << "]";
	delete[] tmp;
	return (out);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_n)
		throw OutOfBoundsException();
	return (this->_ptr[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index > this->_n)
		throw OutOfBoundsException();
	return this->_ptr[index];
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Destructing ARR" << std::endl;
	delete[] this->_ptr;
}



template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Out of bounds.");
}

#endif
