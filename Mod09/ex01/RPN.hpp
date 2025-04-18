#ifndef RPN_H 
# define RPN_H 

# include <iostream>
# include <string>
# include <sstream>
# include <algorithm>
# include <stack>

int setOperators(std::string &operators);
bool isOperator(char ch);
void calculate(std::stack<int> &ops, char oper);


#endif

