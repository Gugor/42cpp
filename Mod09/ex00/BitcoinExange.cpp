#include "BitcoinExange.hpp"


BitcoinExange::BitcoinExange(const std::string db)
{
	this->_entriesPath = db;
	std::cout << "DBPATH: " << this->_entriesPath << std::endl;
}

BitcoinExange::BitcoinExange(const BitcoinExange &other)
{
	*this = other;
}

BitcoinExange &BitcoinExange::operator=(const BitcoinExange &other)
{
	if (this != &other)
	{
		this->_entries = other.getEntries();
	}
	return (*this);
}

BitcoinExange::~BitcoinExange(void){}

const std::map<std::time_t, float> BitcoinExange::getEntries(void) const
{
	return (this->_entries);
}

BitcoinExange::WrongEntryFileFormatException::WrongEntryFileFormatException(const std::string msg)
{                              
        this->_msg = strdup(std::string("Error: ").append(msg).c_str());      
}                              
                               
const char *BitcoinExange::WrongEntryFileFormatException::what(void) const throw()
{                              
        return (this->_msg);
}                              

BitcoinExange::WrongEntryFileFormatException::~WrongEntryFileFormatException(void) throw()
{
	delete this->_msg;
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

std::time_t BitcoinExange::getDate(std::string line, std::size_t separator, std::string &out)
{
        std::string rawDate;  
	struct tm dateTime = {};

        rawDate = line.substr(0, separator - 1);
        trim(rawDate);         
	out = rawDate;
	if (!strptime(rawDate.c_str(), "%Y-%m-%d", &dateTime))
	{
                throw WrongEntryFileFormatException(std::string("bad input =>").append(rawDate));
	}

	return (mktime(&dateTime));
}

float BitcoinExange::getAmount(std::string line, std::size_t separator)
{
        std::string rawAmount;  
        char *end;            

        rawAmount = line.substr(separator + 1);
        trim(rawAmount);         
	std::cout << "RawAmount: " << rawAmount << std::endl;

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
	std::string rawDate;
	std::string rawAmount;
                               
        separator = line.find(ENTRY_SEPARATOR);

        rawDate = line.substr(0, separator - 1);
	std::cout << "Entry Date BTR" << std::endl;
        trim(rawDate);         
	std::cout << "Entry Date ATR" << std::endl;
	if (separator == std::string::npos)
		rawAmount = std::string("");
	else
		rawAmount = line.substr(separator + 1);
        trim(rawAmount);         

	this->_rawentries.insert(std::pair<std::string, std::string>(rawDate, rawAmount));
} 

void BitcoinExange::extractAndInsertDBField(std::string &line)
{                              
        std::size_t separator = 0;
	std::string rawDate;
	std::string rawAmount;
                               
        separator = line.find(DB_SEPARATOR);
        if (separator == std::string::npos)
               throw WrongEntryFileFormatException("no separator");

        rawDate = line.substr(0, separator - 1);
        trim(rawDate);         
        rawAmount = line.substr(separator + 1);
        trim(rawAmount);         

        this->_rawDB.insert(std::pair<std::string, std::string>(rawDate, rawAmount));
	std::cout << "Parsed: " << rawDate << "|=> " << rawAmount << std::endl;  
}

int skipSpaces(std::string &line)
{
	size_t indx = 0;
	while (std::isspace(line[0]))
	{
		indx++;
	}
	return (indx);
}

void BitcoinExange::fetchEntries(const std::string &input)
{
        std::string line;
        std::ifstream fdFile;
	

	std::cout << input << std::endl;
	fdFile.open(input.c_str());
	if (!fdFile)
               throw WrongEntryFileFormatException("could not open file");
	std::getline(fdFile, line);
        while(std::getline(fdFile, line))
        {
		skipSpaces(line);
		try
		{
		    this->extractAndInsertEntry(line);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "RAW LINE:" << line << std::endl;
	}
	fdFile.close();
}

void BitcoinExange::fetchDB(void)
{
        std::string line;
        std::ifstream fdFile;
	

	fdFile.open(this->_entriesPath.c_str());
	if (!fdFile)
               throw WrongEntryFileFormatException("could not open INPUT file");

	std::getline(fdFile, line);
        while(std::getline(fdFile, line))
        {
		skipSpaces(line);
		try
		{
		    this->extractAndInsertDBField(line);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return ;
		}
	}
	fdFile.close();
}

void printEntry(const std::string &t, std::string a)
{
	std::cout << t << " => " << a << std::endl;
}

void BitcoinExange::printEntries(void)
{
	std::map<std::string, std::string>::iterator begin = this->_rawentries.begin();
	std::map<std::string, std::string>::iterator end = this->_rawentries.end();

	while(begin != end)
	{
		printEntry(begin->first, begin->second);
		begin++;
	}
	std::cout << ":: DONE!" << std::endl;
}

void BitcoinExange::printDB(void)
{
	std::map<std::string, std::string>::iterator begin = this->_rawDB.begin();
	std::map<std::string, std::string>::iterator end = this->_rawDB.end();

	while(begin != end)
	{
		printEntry(begin->first, begin->second);
		begin++;
	}
	std::cout << ":: DONE!" << std::endl;
}
