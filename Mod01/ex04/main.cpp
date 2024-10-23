#include <fstream>
#include <string>
#include <iostream>


//1. open file
//2. read line
//3. find ocurrence in line or go copy line in file and go to step 2
//4. if occurence in line 
	//4.1 copy line until occurence in outputace file
	//4.2 copy outputacement string into outputace file
//5  else
	//5.1 copy line
	//go to step 3 

/**
 * @brief It searches occurences of a sting into a file and create a new
 * file with the occurrences outputaced with the string given. 
*/
void outputacefile(std::string fread, std::string foutputace, std::string socurr, std::string soutputace)
{
	std::ifstream	input(fread.c_str());
	if (!input.is_open())
	{
		std::cout << "> Error opening input file" << std::endl;
		return ;
	}
	std::ofstream	output(foutputace.c_str());
	if (!output.is_open())
	{
		std::cout << "> Error opening output file" << std::endl;
		return ;
	}
	std::string		line;
	size_t			occur;

	while (std::getline(input, line))
	{
		occur = line.find(socurr);
		if (occur == std::string::npos)
		{
			if (output.is_open())
				output << line << std::endl;
			continue ;
		}
		output << line.substr(0, occur) << soutputace << line.substr(occur + socurr.length(), line.length()) << std::endl;
	}
	input.close();
	output.close();
}

/**
 * @brief It outputace a given content on a given file
 * with the given string to outputace with.
 * @param filename `{string}` the filename to read
 * @param s1 `{string}` the occurence in the file
 * @param s2 `{sting}` the string to outputace with 
 * @returns `{void}`
*/
int main(int ac, char **av)
{
	if (ac != 4)	
	{
		std::cout << "Wrong number of arguments" << std::endl;
		std::cout << "USAGE: ./powersed [filename] [occurence] [outputacement]" << std::endl;
		return (1);
	}
	outputacefile(av[1], std::string(av[1]).append(".replace"), av[2], av[3]);
	return (0);
}