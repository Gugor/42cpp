#include <fstream>
#include <string>
#include <iostream>


//1. open file
//2. read line
//3. find ocurrence in line or go copy line in file and go to step 2
//4. if occurence in line 
	//4.1 copy line until occurence in replace file
	//4.2 copy replacement string into replace file
//5  else
	//5.1 copy line
	//go to step 3 

/**
 * @brief It searches occurences of a sting into a file and create a new
 * file with the occurrences replaced with the string given. 
*/
void replacefile(std::string fread, std::string freplace, std::string socurr, std::string sreplace)
{
	std::ifstream	toread(fread.c_str());
	std::ofstream	repl(freplace.c_str());
	std::string		line;
	size_t			occur;

	while (std::getline(toread, line))
	{
		occur = line.find(socurr);
		if (occur == std::string::npos)
		{
			if (repl.is_open())
				repl << line << std::endl;
			continue ;
		}
		repl << line.substr(0, occur) << sreplace << line.substr(occur + socurr.length(), line.length()) << std::endl;
	}
}

/**
 * @brief It replace a given content on a given file
 * with the given string to replace with.
 * @param filename `{string}` the filename to read
 * @param s1 `{string}` the occurence in the file
 * @param s2 `{sting}` the string to replace with 
 * @returns `{void}`
*/
int main(int ac, char **av)
{
	if (ac != 4)	
	{
		std::cout << "Wrong number of arguments" << std::endl;
		std::cout << "USAGE: ./powersed [filename] [occurence] [replacement]" << std::endl;
		return (1);
	}
	replacefile(av[1], std::string(av[1]).append(".replace"), av[2], av[3]);
	return (0);
}