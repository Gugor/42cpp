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
	struct tm * timeinfo;
  	char buffer[80];
	time_t t = date.time;

	if (!date.err_msg.empty())
	{
		cout << date.err_msg; 
		return (cout);
	}

  	timeinfo = std::localtime(&t);

	strftime(buffer,sizeof(buffer),"%Y-%m-%d",timeinfo);
	std::string str(buffer);
	cout << str;
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
	float	amount = 0;
	float	rate = 0;
                             
	if (line.empty())
	{
		std::cout << "Error: bad input => empty line" << std::endl;
		return ;
	}
	separator = line.find(ENTRY_SEPARATOR);

	rawDate = line.substr(0, separator - 1);
	trim(rawDate);         
	if (separator == std::string::npos)
		rawAmount = std::string("");
	else
		rawAmount = line.substr(separator + 1);
        trim(rawAmount);         

	t_date date = setDate(rawDate);
	try
	{
		amount = BitcoinExchange::getAmount(rawAmount);
		rate = this->findExchangeRate(date);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	if (date.err_msg.empty())
		std::cout << date <<  " => " << amount << " * "  << rate << " = " <<  
			(amount * rate) << std::endl; 
	else
		std::cout << date.err_msg << std::endl;
} 

bool checkStrDate(std::string &rawDate)
{
	int indx = -1;
	if (rawDate.empty())
		return (false);
	while(rawDate[++indx])
	{
		if (!std::isdigit(rawDate[indx]) && rawDate[indx] != '-')
				return (false);
	}
	return (true);
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
		throw WrongEntryFileFormatException("wrong header file");
		exit (1);
	}

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
	}
	fdFile.close();
}

void BitcoinExchange::extractAndInsertDBField(std::string &line)
{                              
  std::size_t separator = 0;
	std::string rawDate;
	std::string rawAmount;
	float amount = 0;
                               

	separator = line.find(DB_SEPARATOR);
	if (line.empty())
	      throw WrongEntryFileFormatException("incorrect DB formating. Empty lines");

	if (separator == std::string::npos)
		   throw WrongEntryFileFormatException("no separator");

	rawDate = line.substr(0, separator);
	trim(rawDate);         
  if (!checkStrDate(rawDate))
      throw WrongEntryFileFormatException("corrupted DB");
	rawAmount = line.substr(separator + 1);
	trim(rawAmount);         
	t_date date = setDate(rawDate);	
	try 
	{
		amount = BitcoinExchange::getAmount(rawAmount);
	}
	catch(std::exception &e){}
	this->_rawDB.insert(std::pair<t_date, float>(date, amount));
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
         throw WrongEntryFileFormatException("empty file or worng DB format");
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

t_date BitcoinExchange::setDate(std::string &rawDate)
{
	struct tm dateTime = {};
	t_date date = {};

	trim(rawDate);         
	if (!checkStrDate(rawDate))
	{
		date.err_msg = std::string("Error: bad input => ").append(rawDate);
		return (date);
	}
	if (!strptime(rawDate.c_str(), "%Y-%m-%d", &dateTime))
	{
		date.err_msg = std::string("Error: bad input => ").append(rawDate);	
	}
	else
	{
		date.date = dateTime;
		date.time = std::mktime(&dateTime);
	}
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
	if (amount > 1000)
                throw BitcoinExchange::WrongEntryFileFormatException("number too large");

	return (amount);
}

float BitcoinExchange::findExchangeRate(t_date &date)
{
	BitcoinExchange::InputDB::reverse_iterator begin = this->_rawDB.rbegin();
	BitcoinExchange::InputDB::reverse_iterator end = this->_rawDB.rend();
	std::time_t dbdate;
	float		rate = 0;

	if (!date.err_msg.empty())
		return (-1);
	while (begin != end)
	{
		dbdate = begin->first.time;	
		if (dbdate <= date.time)
			return (begin->second);
		begin++;
	}
	return (rate);
}





