
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define SIZE 9

int main(void)
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();


	delete dog;	
	delete cat;	
	Animal *pack[SIZE];

	for(int i=0; i < SIZE ; i++)
	{	
		if (i % 2 == 0)
			pack[i] = new Dog();
		else
			pack[i] = new Cat();
	}
	for (int i=0; i < SIZE; i++)	
		delete pack[i];
}
