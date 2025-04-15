#include "RPN.hpp"

RPN::RPN(std::string &operation)
{
	std::cout << "Parsing" << std::endl;
	this->_doOperation(operation);	
}

RPN::~RPN(void){}

unsigned char unisspace(unsigned char ch)
{
	return (!std::isspace(ch));
}


std::ostream &operator<<(std::ostream &out, std::vector<char> &operations)
{
	std::vector<char>::iterator begin = operations.begin();
	std::vector<char>::iterator end = operations.end();
	while(begin != end)
	{
		if (begin + 1 != end)
			out << (*begin) << " ";
		else
			out << (*begin);
		begin++;
	}
	out << "$";
	return (out);
}

void trim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), &unisspace));
}

void RPN::_setOperators(std::string &operators)
{
	char ch = 0;
	size_t end = 0;
	std::string str;

	while(!operators.empty())
	{
		trim(operators);
		end = operators.find(" ");
		str = operators.substr(0, end); 
		if (str.size() > 1)
		{
			throw std::invalid_argument("Error: number to high");
			return;
		}
		this->_operation.push_back(ch);
		if (end == std::string::npos)
			return ;
		operators.erase(0, end);
	}
}

bool RPN::_isOperator(char ch)
{
	std::string set("+-*/");
	if (set.find(ch))
		return (true);
	else
		return (false);
}

bool RPN::_checkOperation(void)
{
	std::vector<char>::iterator begin = operations.begin();
	std::vector<char>::iterator end = operations.end();

	std::cout << "Cheking operations" << std::endl;
	std::cout << "Start: " << (*begin)<< "/" <<(*begin + 1) << std::endl;
	std::cout << "Correct start: " << (!std::isdigit((*begin))&& !std::isdigit((*begin + 1))) << std::endl;
	if (!std::isdigit((*begin)) && !std::isdigit((*begin + 1))) 
	{
		throw std::invalid_argument("Error: not valid argument");
		exit(0);
	}


	if (!this->_isOperator((*end - 1])))
	{
		throw std::invalid_argument("Error: not valid argument");
		exit(0);
	}

	while (begin != end())
	{
		if (!std::isdigit((*begin)) && !this->_isOperator((*begin))) 
		{
			throw std::invalid_argument("Error: not valid argument");
			exit(0);
		}
		begin++;
	}
	std::cout << "All good" << std::endl;
	return (true);
}

void RPN::_doOperation(std::string &operation)
{
	trim(operation);	
	std::cout << "Operation: " << operation << std::endl;
	try 
	{
		if (this->_checkOperation(operation))
			this->_setOperators(operation);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		exit(0);
	}
	std::cout << this->_operation << std::endl;
}


