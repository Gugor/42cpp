#include "Base.hpp"
#include <cstdlib>
#include <ctime>


int main (void)
{
	std::srand(time(NULL));
	{
		Base	*base;


		base = generate();
		identify(base);
	}
	{
		Base	*base;

		base = generate();
		Base	&rbase = *base;
		identify(rbase);

	}
	return (0);
}
