#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "A new head as being has being filled with a default brain" << std::endl;
	this->_createIdeas();
}

Brain::Brain(const Brain &other)
{
	if (this != &other)
	{
		*this = other;
	}	
	std::cout << "A new head tansplant has beeing done, successfully! Well we hope..." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i=0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}	
	std::cout << "We have done new brain assignation! Hurray!" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "This brain is _____________" << std::endl;
}

void Brain::_createIdeas()
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "A wonderfull idea";
	}
}

void Brain::printIdeas() const
{
	//ideas = this->_ideas;
}
