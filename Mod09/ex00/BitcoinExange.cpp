#include "BitcoinExange.hpp"

BitcoinExange::BitcoinExange(void){}

BitcoinExange::~BitcoinExange(void){}

const std::map<std::time_t, float> BitcoinExange::getEntries(void) const
{
	return (this->_entries);
}

BitcoinExange::WrongEntryFileFormatException::WrongEntryFileFormatException(const std::string msg)
{                              
        this->_msg = msg;      
}                              
                               
const char *BitcoinExange::WrongEntryFileFormatException::what(void) const throw()
{                              
        return (std::string("Error: ").append(this->_msg).c_str());
}                              
                               
unsigned char unisspace(unsigned char ch)
{
	return !std::isspace(ch);
}

void trim(std::string s)       
{                              
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), &unisspace));                       
        s.erase(std::find_if(s.rbegin(), s.rend(), &unisspace).base(), s.end());       
}                              

std::time_t BitcoinExange::getDate(std::string line, std::size_t separator)
{
        std::string rawDate;  
	struct tm dateTime;
	std::time_t date;
	char *end;

        rawDate = line.substr(0, separator - 1);
        trim(rawDate);         
	end = NULL;
	errno = 0;
	dateTime.tm_year = std::strtof(rawDate.substr(0,4).c_str(), &end);
        if (errno == ERANGE || *end != '-')
                throw WrongEntryFileFormatException(std::string("bad input =>").append(rawDate));
	errno = 0;
	dateTime.tm_mon = std::strtof(rawDate.substr(5,2).c_str(), &end);
        if (errno == ERANGE || *end != '-')
                throw WrongEntryFileFormatException(std::string("bad input =>").append(rawDate));
	errno = 0;
	dateTime.tm_mday = std::strtof(rawDate.substr(8,2).c_str(), &end);
        if (errno == ERANGE || *end != '\0')
                throw WrongEntryFileFormatException(std::string("bad input =>").append(rawDate));
	date = mktime(&dateTime);	

	return (date);
}

float BitcoinExange::getAmount(std::string line, std::size_t separator)
{
        std::string rawAmount;  
        char *end;            

        rawAmount = line.substr(separator + 1);
        trim(rawAmount);         

        float amount = std::strtof(rawAmount.c_str(), &end);
        if (*end != '\0')
                throw WrongEntryFileFormatException("wrong amount format");
        if (errno == ERANGE)
                throw WrongEntryFileFormatException("number too large");
	if (amount < 0)
                throw WrongEntryFileFormatException("not a positive number");

	return (amount);
}

void BitcoinExange::extractAndInsertEntry(std::string &line)
{                              
        std::size_t separator = 0;
	std::time_t date;
	float	amount;
                               
        separator = line.find(ENTRY_SEPARATOR);

        if (separator == std::string::npos)
               throw WrongEntryFileFormatException("no separator");

	date = getDate(line, separator);
	amount = getAmount(line, separator);
                               
        this->_entries.insert(std::pair<std::time_t, float>(date, amount));
}

void BitcoinExange::fetchEntries(const std::string &entriesFile)
{
        std::string line;
        std::ifstream fdFile;
	

	fdFile.open(entriesFile.c_str());
	if (!fdFile)
               throw WrongEntryFileFormatException("could not open file");
	
        while(std::getline(fdFile, line))
        {
		try
		{
		    this->extractAndInsertEntry(line);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	fdFile.close();
}

/*
    std::ifstream file("Read.txt");
    std::string str;
    while (std::getline(file, str))
    {
        // Process str
    }
*/

void printEntry(std::time_t t, float a)
{
	std::cout << t << " => " << a << std::endl;
}

void BitcoinExange::printEntries(void)
{
	std::map<std::time_t, float>::iterator begin = this->_entries.begin();
	std::map<std::time_t, float>::iterator end = this->_entries.end();

	while(begin != end)
	{
		printEntry(begin->first, begin->second);
		begin++;
	}
	std::cout << ":: DONE!" << std::endl;
}

