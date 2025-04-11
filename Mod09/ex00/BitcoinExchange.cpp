#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(const std::string db)
{
	this->_dbPath = db;
	this->fetchDB();
	std::cout << "DBPATH: " << this->_dbPath << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_dbPath = other.getDBPath();
		if (!other.getEntries().empty())
			this->_rawentries = other.getEntries();
		this->fetchDB();
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void){}

const std::map<std::string, std::string> BitcoinExchange::getEntries(void) const
{
	return (this->_rawentries);
}

BitcoinExchange::WrongEntryFileFormatException::WrongEntryFileFormatException(const std::string msg)
{                              
        this->_msg = strdup(std::string("Error: ").append(msg).c_str());      
}                              
                               
const char *BitcoinExchange::WrongEntryFileFormatException::what(void) const throw()
{                              
        return (this->_msg);
}                              

BitcoinExchange::WrongEntryFileFormatException::~WrongEntryFileFormatException(void) throw()
{
	delete this->_msg;
}                              
                               
unsigned char unisspace(unsigned char ch)
{
	return !std::isspace(ch);
}

void trim(std::string &s)       
{                              
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), &unisspace));                       
        s.erase(std::find_if(s.rbegin(), s.rend(), &unisspace).base(), s.end());       
}                              

const std::string &BitcoinExchange::getDBPath(void) const
{
	return (this->_dbPath);
}


void BitcoinExchange::extractAndInsertEntry(std::string &line)
{                              
	std::size_t separator = 0;
	std::string rawDate;
	std::string rawAmount;
                               
    separator = line.find(ENTRY_SEPARATOR);

    rawDate = line.substr(0, separator - 1);
    trim(rawDate);         
	if (separator == std::string::npos)
		rawAmount = std::string("");
	else
		rawAmount = line.substr(separator + 1);
        trim(rawAmount);         

	this->_rawentries.insert(std::pair<std::string, std::string>(rawDate, rawAmount));
	//std::cout << "Parsed: " << rawDate << "|=> " << rawAmount << std::endl;  
} 


size_t skipSpaces(std::string &line)
{
	size_t indx = 0;
	while (std::isspace(line[0]))
	{
		indx++;
	}
	return (indx);
}

void BitcoinExchange::fetchEntries(const std::string &input)
{
        std::string line;
        std::ifstream fdFile;
	

	std::cout << input << std::endl;
	this->_rawentries.clear();
	fdFile.open(input.c_str());
	if (!fdFile)
               throw WrongEntryFileFormatException("could not open INPUT file");

	std::getline(fdFile, line);
    while(std::getline(fdFile, line))
    {
		trim(line);
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

void BitcoinExchange::extractAndInsertDBField(std::string &line)
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
	//std::cout << "Parsed: " << rawDate << "|=> " << rawAmount << std::endl;  
}

void BitcoinExchange::fetchDB(void)
{
        std::string line;
        std::ifstream fdFile;
	

	this->_rawDB.clear();
	std::cout << this->_dbPath << std::endl;
	fdFile.open(this->_dbPath.c_str());
	if (!fdFile)
               throw WrongEntryFileFormatException("could not open DB file");

	std::getline(fdFile, line);
	while(std::getline(fdFile, line))
	{
		trim(line);
		try
		{
		    this->extractAndInsertDBField(line);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			exit(0);
		}
	}
	fdFile.close();
}

void printEntry(const std::string &t, std::string a)
{
	std::cout << t << " => " << a << std::endl;
}

void BitcoinExchange::printEntries(void)
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

std::time_t BitcoinExchange::getDate(std::string rawDate)
{
	struct tm dateTime = {};

	trim(rawDate);         
	if (!strptime(rawDate.c_str(), "%Y-%m-%d", &dateTime))
	{
                throw BitcoinExchange::WrongEntryFileFormatException(std::string("bad input => ").append(rawDate));
	}

	return (mktime(&dateTime));
}

float BitcoinExchange::getAmount(std::string rawAmount)
{
	char *end;            

	trim(rawAmount);         

	float amount = std::strtof(rawAmount.c_str(), &end);
	if (*end != '\0')
			throw BitcoinExchange::WrongEntryFileFormatException("wrong amount format");
	if (errno == ERANGE)
			throw BitcoinExchange::WrongEntryFileFormatException("number too large");
	if (amount < 0)
                throw BitcoinExchange::WrongEntryFileFormatException("not a positive number");

	return (amount);
}

float BitcoinExchange::findExchangeRate(std::time_t date)
{
	RawDB::iterator begin = this->_rawDB.begin();
	RawDB::iterator end = this->_rawDB.end();
	std::time_t dbdate;
	std::time_t closest = this->getDate(begin->first);
	std::time_t	dist = 0;
	std::time_t	prevdist = std::abs(closest - date) + 1;
	float		rate = 0;

	while (begin != end)
	{
		dbdate = this->getDate(begin->first);	
		dist = std::abs(date - dbdate);
		if (dist == 0)
			return (this->getAmount(begin->second));
		if (prevdist == dist)
		{
			if (closest < dbdate)
			{
				closest = dbdate; 
				rate = this->getAmount(begin->second);
			}
		}
		else if (prevdist > dist)
		{
			prevdist = dist;
			rate = this->getAmount(begin->second);
			closest = dbdate;
		}
		begin++;
	}
	return (rate);
}

void BitcoinExchange::showExchangeRates(void)
{
	RawInputDB::iterator begin = this->_rawentries.begin();
	RawInputDB::iterator end = this->_rawentries.end();

	time_t date = 0;
	float amount = 0;

	while (begin != end)
	{
		std::cout << "Show Exchange: " << begin->first << "|" << begin->second << std::endl;
		try 
		{
			date = BitcoinExchange::getDate(begin->first);
			amount = BitcoinExchange::getAmount(begin->second);
			std::cout << begin->first << " => " << amount * this->findExchangeRate(date) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		begin++;
	}
	//while(getInputField == true)
		//throw Input error
		//findNearestInDB()
		//computeChange()
		//printchange
		//<-++
}

void BitcoinExchange::printDB(void)
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
