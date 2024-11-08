#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat(void);

		void makeSound(void) const;
		std::string getAnimalType(void) const;
};


#endif
