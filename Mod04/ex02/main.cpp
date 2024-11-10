
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define SIZE 4

int main(void)
{
	{
		std::cout << "=== First set of tests ===" << std::endl;
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << std::endl;

		delete dog;	
		delete cat;	
	}

	std::cout << std::endl;
	{
		std::cout << "=== Second set of tests ===" << std::endl;
		Animal *pack[SIZE];

		for(int i=0; i < SIZE ; i++)
		{	
			std::cout << "[" << i << "]:" << std::endl;
			if (i % 2 == 0)
				pack[i] = new Dog();
			else
				pack[i] = new Cat();
			pack[i]->makeSound();
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << "** Pack Deletion **" << std::endl;
		for (int i=0; i < SIZE; i++)	
		{
			std::cout << "[" << i << "]:" << std::endl;
			delete pack[i];
			std::cout << std::endl;
		}
	}
	{
		//Animal animal;
	}
}
