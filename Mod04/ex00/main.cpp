#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* cat = new Cat();
		const Animal* dog = new Dog();

		std::cout << dog->getAnimalType() << " " << std::endl;
		std::cout << cat->getAnimalType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		meta->makeSound();
		std::cout << std::endl;
		delete meta;
		delete dog;
		delete cat;
		std::cout << std::endl;
	}
	{
		std::cout << "== Wrong Scope ==" << std::endl;
		std::cout << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();

		std::cout << cat->getAnimalType() << " " << std::endl;
		cat->makeSound();
		meta->makeSound();
		std::cout << std::endl;
		delete meta;
		delete cat;
		std::cout << std::endl;
	}
}
