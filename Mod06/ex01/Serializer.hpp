#ifndef SERIALIZER_H 
# define SERIALIZER_H 

# include <iostream>
# include <string>

struct Data 
{
	int someInt;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &serializer);
		~Serializer(void);
	public:
		static	uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif

