#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat(void);

		void makeSound(void) const;
		std::string getAnimalType(void) const;
};


#endif
