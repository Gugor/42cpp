#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog(void);

		void makeSound() const;
		std::string getAnimalType() const;
};


#endif
