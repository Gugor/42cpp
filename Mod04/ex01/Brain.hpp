#ifndef BRIAN_H
#define BRIAN_H

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
		void _createIdeas();
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		virtual ~Brain(void);
		
		void printIdeas() const;

};


#endif
