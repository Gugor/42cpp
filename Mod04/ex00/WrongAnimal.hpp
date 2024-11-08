#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;	

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal(const std::string type);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal(void);
		
		void makeSound(void) const;

		std::string getAnimalType(void) const;
};



#endif
