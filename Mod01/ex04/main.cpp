#include <fstream>
#include <string>
#include <iostream>


/**
 * @brief It searches occurences of a sting into a file and create a new
 * file with the occurrences outputd with the string given. 
*/
void outputfile(std::string fread, std::string foutput, std::string soccur, std::string soutput)
{
	std::ifstream	input(fread.c_str());
	if (!input.is_open())
	{
		std::cout << "> Error opening input file" << std::endl;
		return ;
	}
	std::ofstream	output(foutput.c_str());
	if (!output.is_open())
	{
		std::cout << "> Error opening output file" << std::endl;
		return ;
	}
	std::string		line;
	size_t			occur = 1;
	std::string		buff;	

	while (std::getline(input, line))
	{
		while ((occur = line.find(soccur)) < std::string::npos)
		{
			buff.append(line);
			line.clear();
			line.append(buff, 0, occur);
			line.append(soutput);
			line.append(buff, occur + soccur.length(), buff.length());
			buff.clear();
		}
		output << line << std::endl;
		buff.clear();
	}
	input.close();
	output.close();
}

/**
 * @brief It output a given content on a given file
 * with the given string to output with.
 * @param filename `{string}` the filename to read
 * @param s1 `{string}` the occurence in the file
 * @param s2 `{sting}` the string to output with 
 * @returns `{void}`
*/
int main(int ac, char **av)
{
	if (ac != 4)	
	{
		std::cout << "Wrong number of arguments" << std::endl;
		std::cout << "USAGE: ./powersed [filename] [occurence] [outputment]" << std::endl;
		return (1);
	}
	outputfile(av[1], std::string(av[1]).append(".replace"), av[2], av[3]);
	return (0);
}
