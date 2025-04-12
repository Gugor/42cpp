#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(const std::string db)
{
	this->_dbPath = db;
	try
	{
		this->fetchDB();
	}
	catch (std::exception &e)
	{ 
		std::cerr << e.what() << std::endl;
		exit(1);
	}
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
		try
		{
			this->fetchDB();
		}
		catch (std::exception &e)
		{ 
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &cout, const t_date &date)
{
	cout << date.date.tm_year << "-" << date.date.tm_year << "-" << date.date.tm_year;
	return (cout);
}

bool operator<(const t_date &k1, const t_date &k2)
{
	if (k1.time < k2.time)
		return (true);
	else
		return (false);
}

BitcoinExchange::~BitcoinExchange(void){}

const BitcoinExchange::InputDB BitcoinExchange::getEntries(void) const
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

	t_date date = setDate(rawDate);
	this->_rawentries.insert(std::pair<t_date, float>(date, BitcoinExchange::getAmount(rawAmount)));
	std::cout << "Parsed: " << rawDate << "|=> " << rawAmount << std::endl;  
	std::cout << "++ Check Insetion ++" << std::endl;
	this->printEntries();
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
	if (!fdFile.is_open())
	{
	       throw WrongEntryFileFormatException("could not open INPUT file");
	       exit (1);
	}

	std::getline(fdFile, line);
	if (line.empty())
	{
               throw WrongEntryFileFormatException("empty file");
	       exit (1);
	}

	trim(line);
	if (line != ENTRY_HEADER_FILE)
	{
		std::cout << "Fetch Input error:" << line << std::endl;
		throw WrongEntryFileFormatException("wrong header file");
		exit (1);
	}

	while(std::getline(fdFile, line))
	{
		trim(line);
		if (line == "\n")
			continue;
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
	t_date date = setDate(rawDate);
	std::cout << "Parsed: " << date.date.tm_year << "|=> " << rawAmount << std::endl;  
    this->_rawDB.insert(std::pair<t_date, float>(date, BitcoinExchange::getAmount(rawAmount)));
}

void BitcoinExchange::fetchDB(void)
{
        std::string line;
        std::ifstream fdFile;
	

	this->_rawDB.clear();
	std::cout << this->_dbPath << std::endl;
	fdFile.open(this->_dbPath.c_str());
	if (!fdFile.is_open())
	{
               throw WrongEntryFileFormatException("could not open DB file");
	       exit(1);
	}

	std::getline(fdFile, line);
	if (line.empty())
	{
               throw WrongEntryFileFormatException("empty file");
	       exit(1);
	}

	trim(line);
	if (line != DB_HEADER_FILE)
	{
               throw WrongEntryFileFormatException("wrong header file");
	       exit(1);
	}

	while(std::getline(fdFile, line))
	{
		trim(line);
		if (line == "\n")
			continue;
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

bool checkStrDate(std::string rawDate)
{
	int indx = -1;
	if (rawDate.empty())
		return (false);
	while(rawDate[++indx])
	{
		if (!std::isdigit(rawDate[indx] && rawDate[indx] != '-'))
				return (false);
	}
	return (true);
}

t_date BitcoinExchange::setDate(std::string rawDate)
{
	struct tm dateTime = {};
	t_date date = {};

	trim(rawDate);         
	if (!checkStrDate(rawDate))
	{
		date.err_msg = std::string("bad input => ").append(rawDate);
		return (date);
	}

	if (!strptime(rawDate.c_str(), "%Y-%m-%d", &dateTime))
	{
		date.err_msg = std::string("bad input => ").append(rawDate);	
	}
	else
	{
		date.date = dateTime;
		date.time = std::mktime(&dateTime);
	}
	std::cout << "	!!! " <<date.date.tm_year << std::endl;
	return (date);
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
	BitcoinExchange::InputDB::iterator begin = this->_rawDB.begin();
	BitcoinExchange::InputDB::iterator end = this->_rawDB.end();
	std::time_t dbdate;
	std::time_t closest = begin->first.time;
	std::time_t	dist = 0;
	std::time_t	prevdist = std::abs(closest - date) + 1;
	float		rate = 0;

	while (begin != end)
	{
		dbdate = begin->first.time;	
		dist = std::abs(date - dbdate);
		if (dist == 0)
			return (begin->second);
		if (prevdist == dist)
		{
			if (closest < dbdate)
			{
				closest = dbdate; 
				rate = begin->second;
			}
		}
		else if (prevdist > dist)
		{
			prevdist = dist;
			rate = begin->second;
			closest = dbdate;
		}
		begin++;
	}
	return (rate);
}

void BitcoinExchange::showExchangeRates(void)
{
	BitcoinExchange::InputDB::reverse_iterator begin = this->_rawentries.rbegin();
	BitcoinExchange::InputDB::reverse_iterator end = this->_rawentries.rend();

	//time_t date = 0;
	//float amount = 0;

	while (begin != end)
	{
		std::cout << "Show Exchange: " << begin->first << "|" << begin->second << std::endl;
		//	date = BitcoinExchange::getDate(begin->first);
		//	amount = BitcoinExchange::getAmount(begin->second);
			if (begin->first.err_msg.empty())	
				std::cout << begin->first << " => " << (begin->second * this->findExchangeRate(begin->first.time)) << std::endl;
			else
				throw BitcoinExchange::WrongEntryFileFormatException(begin->first.err_msg);
				
		begin++;
	}
}


void printEntry(const t_date &t, float a)
{
	std::cout << t << " => " << a << std::endl;
}

void BitcoinExchange::printEntries(void)
{
	BitcoinExchange::InputDB::reverse_iterator begin = this->_rawentries.rbegin();
	BitcoinExchange::InputDB::reverse_iterator end = this->_rawentries.rend();

	while(begin != end)
	{
		printEntry(begin->first, begin->second);
		begin++;
	}
	std::cout << ":: DONE!" << std::endl;
}

void BitcoinExchange::printDB(void)
{
	BitcoinExchange::InputDB::iterator begin = this->_rawDB.begin();
	BitcoinExchange::InputDB::iterator end = this->_rawDB.end();

	while(begin != end)
	{
		printEntry(begin->first, begin->second);
		begin++;
	}
	std::cout << ":: DONE!" << std::endl;
}

