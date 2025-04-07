#include "BitcoinExange.hpp"


BitcoinExange::BitcoinExange(const std::string bd)
{
	this->_bd = bd;
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

/*
int check_year(std::string y, struct tm date)
{
	int year = static_cast<int>(std::strtol(rawDate.substr(0,4).c_str(), &end, 10)) - 1900;
	char *end;

	end = NULL;
	errno = 0;
        if (errno != 0 || *end != '\0' || year < 1900)
		return (1)
	dateTime.tm_year = year - 1900;
	return (0);
}

int check_mon(std::string y, struct tm date)
{
	int mon = static_cast<int>(std::strtol(rawDate.substr(0,4).c_str(), &end, 10)) - 1900;
	char *end;

	end = NULL;
	errno = 0;
	
        if (errno != 0 || *end != '\0' || mon > 31)
		return (1);
	dateTime.tm_mon = mon - 1900;
	return (0);
}
*/


std::time_t BitcoinExange::getDate(std::string line, std::size_t separator, std::string &out)
{
        std::string rawDate;  
	struct tm dateTime = {};
//	std::time_t date;


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
	std::time_t date;
	float	amount;
	std::string rawDate;
                               
        separator = line.find(ENTRY_SEPARATOR);

        if (separator == std::string::npos)
               throw WrongEntryFileFormatException("no separator");

	date = getDate(line, separator, rawDate);
	amount = getAmount(line, separator);
	std::cout << amount << std::endl;
                               
        this->_entries.insert(std::pair<std::time_t, float>(date, amount));
        this->_rawentries.insert(std::pair<std::string, float>(rawDate, amount));
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

void BitcoinExange::fetchEntries(const std::string &entriesFile)
{
        std::string line;
        std::ifstream fdFile;
	

	fdFile.open(entriesFile.c_str());
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
	}
	fdFile.close();
}

void printEntry(const std::time_t &t, float a)
{
	char buffer[11];
	struct tm *timeinfo;
	time_t time = t;
	
	std::time (&time);
	timeinfo = std::localtime(&time);
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
	std::cout << std::string(buffer) << " => " << a << std::endl;
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

