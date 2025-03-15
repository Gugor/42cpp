#include "Serializer.hpp"

int main (void)
{
	Data data;
	Data *unser;
	uintptr_t ser;

	data.someInt = 1441; 

	ser = Serializer::serialize(&data);
	unser = Serializer::deserialize(ser);	

	std::cout << " | Original: " << data << "\n | Serialized: (" << &ser << ")[" << ser << "]\n | Deserialized: " << *unser << std::endl;
		
	return (0);
}
