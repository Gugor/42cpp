#ifndef SERIALIZER_H 
# define SERIALIZER_H 

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct sData 
{
	int someInt;
}	Data;

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

std::ostream &operator<<(std::ostream &out, const Data &data);

#endif

