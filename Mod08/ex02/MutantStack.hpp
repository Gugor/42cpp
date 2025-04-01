#ifndef MUTANTSTACK_H 
# define MUTANTSTACK_H 

# include <iostream>
# include <stack>
# include <deque>
# include <iterator>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack<T, Container> &other);
		MutantStack(const Container &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack(void);

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);	
};

template< typename T, typename Container >
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>(){}


template< typename T, typename Container >
MutantStack<T, Container>::MutantStack(const MutantStack &other) : std::stack<T, Container>(other){}

template< typename T, typename Container >
MutantStack<T, Container>::MutantStack(const Container &other) : std::stack<T, Container>(other){}

template< typename T, typename Container >
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &other)
{
	if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
	return(*this);
}

template< typename T, typename Container >
MutantStack<T, Container>::~MutantStack(void){}

template< typename T, typename Container >
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template< typename T, typename Container >
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

#endif

