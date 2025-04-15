#ifndef RPN_H 
# define RPN_H 

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class RPN
{
	public:
		RPN(std::string &operation);
		~RPN(void);
	private:
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &rpn);
		void _setOperators(std::string &operators);
		void _doOperation(std::string &operation);
		bool _checkOperation(std::string &operations);
		bool _isOperator(char ch);
		typedef int (*operation)(int, int);
		int _sum(int a, int b);
		int _div(int a, int b);
		int _rest(int a, int b);
		int _mult(int a, int b);
		std::vector<operation> _fnOperations;
		std::vector<char> _operation;
};

#endif

