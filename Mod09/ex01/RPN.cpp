#include "RPN.hpp"


bool isOperator(char ch)
{
	std::string set("+-/*");
	if (set.find(ch) != std::string::npos)
		return (true);
	else
		return (false);
}


void calculate(std::stack<int> &ops, char oper)
{

	if (ops.size() < 2)
			throw std::invalid_argument("Error: invalid argument");

	int op1 = ops.top();
	ops.pop();
	int op2 = ops.top();
	ops.pop();
	switch(oper)
	{
		case '+': ops.push(op2 + op1); break;
		case '-': ops.push(op2 - op1); break;
		case '*': ops.push(op2 * op1); break;
		case '/': 
				  if (op1 == 0 || op2 == 0)
            throw std::invalid_argument("Error: division by 0");
				  ops.push(op2 / op1); break;
		default: throw std::invalid_argument("Error: operator unknown");
	}
}

int setOperators(std::string &operators)
{
	std::istringstream str(operators);
	std::stack<int> ops;
	std::string line;

	while(getline(str, line, ' '))
	{
		if (line.size() != 1)
			throw std::invalid_argument("Error: invalid argument. > 9");
		if (isOperator(line[0]))
			calculate(ops, line[0]);
		else if (std::isdigit(line[0]))
			ops.push(std::atoi(&line[0]));
		else
			throw std::invalid_argument("Error: invalid argument");
	}
	if (ops.size() != 1)
			throw std::invalid_argument("Error: bad operation formatting");
	return (ops.top());

}



