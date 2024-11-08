#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>


class Animal
{
	protected:
		std::string _type;	


	public:
		Animal(void);
		Animal(const Animal &other);
		Animal(const std::string type);
		Animal &operator=(const Animal &other);
		virtual ~Animal(void);
		
		virtual void makeSound(void) const;

		virtual std::string getAnimalType(void) const;
};

#endif
