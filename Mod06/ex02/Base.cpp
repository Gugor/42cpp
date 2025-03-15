#include "Base.hpp"
#include <cstdlib> 
#include <ctime> 

Base::~Base(void){}

Base *generate(void)
{
	int select = std::rand() % 3;
	
	if (select == 0)
		return (new A);
	else if (select == 1)
		return (new B);
	else if (select == 2) 
		return (new C);
	return (new Base);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It's type A (ptr)" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's type B (ptr)" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's type C (ptr)" << std::endl;
}

void identify(Base &p)
{
	try
	{ 
		(void)dynamic_cast<A&>(p);
		std::cout << "It's type A (ref)" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{ 
		(void)dynamic_cast<B&>(p);
		std::cout << "It's type B (ref)" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{ 
		(void)dynamic_cast<C&>(p);
		std::cout << "It's type C (ref)" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	return ;
}
