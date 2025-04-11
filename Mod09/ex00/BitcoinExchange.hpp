#ifndef BITCOINEXCHANGE_H 
# define BITCOINEXCHANGE_H 

# include <iostream>
# include <ctime>
# include <cstring>
# include <fstream>
# include <algorithm>
# include <map>
# include <exception>

#define ENTRY_SEPARATOR "|"
#define DB_SEPARATOR ","

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string bd);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &bitcoinexange);
		~BitcoinExchange(void);
		const std::map<std::string, std::string> getEntries(void) const; 
		const std::string &getDBPath(void) const;
		void fetchEntries(const std::string &input);
		void fetchDB(void);
		void showExchangeRates(void);
		void printEntries(void);
		void printDB(void);

		class WrongEntryFileFormatException : public std::exception
		{
			public:
				WrongEntryFileFormatException(std::string msg);
				virtual const char *what(void) const throw();
				virtual ~WrongEntryFileFormatException(void) throw();
			protected:
				char *_msg;
		};


	private:
		BitcoinExchange(void);
		typedef std::map<std::time_t, float> InputDB;
		typedef std::map<std::string, std::string> RawInputDB;
		typedef std::map<std::string, std::string> RawDB;
		RawInputDB _rawentries;
		RawDB _rawDB;
		std::string _dbPath;
		void extractAndInsertEntry(std::string &line);
		void extractAndInsertDBField(std::string &line);
		std::time_t getDate(std::string line);
		float getAmount(std::string line);
		float findExchangeRate(std::time_t time);
};

#endif

