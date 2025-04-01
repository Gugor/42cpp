#ifndef MUTANTSTACK_H 
# define MUTANTSTACK_H 

# include <iostream>
# include <deque>

/*
(constructor)
    Construct stack (public member function)

empty
    Test whether container is empty (public member function)

size
    Return size (public member function)

top
    Access next element (public member function)

push
    Insert element (public member function)

emplace
    Construct and insert element (public member function)

pop
    Remove top element (public member function)

swap 

*/

template<typename T, typename Container = std::deque<T> >
class MutantStack
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack<T, Container> &other);
		MutantStack(const Container &other);
		MutantStack &operator=(const Container &mutantstack);
		~MutantStack(void);
		std::string getName(void) const; 

		bool empty(void);
		size_t size(void);
		T top(void);
		void push(T element);
		void emplace(T element);
		void pop(void);
		void swap(T element);
	private:
		std::stack<T, Container> _stack;
};

template<typename T, typename Container = std::deque<T>>
MutantStack(void){}


template<typename T, typename Container = std::deque<T>>
MutantStack(const MutantStack<T, Container> &other)
{
	this->stack<T, Container> = other;
}

template<typename T, typename Container = std::deque<T>>
MutantStack(const Container &other)
{
	this->stack<T, Container>(other);
}

template<typename T, typename Container = std::deque<T>>
MutantStack &operator=(const Container &mutantstack)
{
	if (*this != other)
	{
		this->_stack(mutantstack);
	}
	return (*this);
}

template<typename T, typename Container = std::deque<T>>
bool empty(void)
{

}

#endif

