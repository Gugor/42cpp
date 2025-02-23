
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{	
	{
		Bureaucrat An;
		Bureaucrat Steve("Steve", 1);
		Bureaucrat SteveCpy;
		Form	A1B2C3("A1B2C3", 1);
		Form	B2C3D4;
		SteveCpy = Steve;

		std::cout << std::endl;
		try 
		{
			Form	C3D4E5("C3D4E5", 151);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to create Form with such a low grade." << std::endl;	
		}

		try
		{
			B2C3D4 = Form("B2C3D4", 0);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": " << B2C3D4 << "	:: not possible to increment grade" << std::endl;	
		}

		std::cout << std::endl;
	}
}
