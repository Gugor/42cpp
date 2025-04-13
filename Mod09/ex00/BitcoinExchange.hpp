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
#define ENTRY_HEADER_FILE "date | value"
#define DB_SEPARATOR ","
#define DB_HEADER_FILE "date,exchange_rate"

typedef struct btc_date 
{
	struct tm date;
	std::time_t time;
	std::string err_msg;
}	t_date;

class BitcoinExchange
{
	public:
		typedef std::map<t_date, float> InputDB;
		BitcoinExchange(const std::string bd);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &bitcoinexange);
		~BitcoinExchange(void);
		const InputDB getEntries(void) const; 
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
	//	typedef std::map<std::string, std::string> RawInputDB;
		//typedef std::map<std::string, std::string> RawDB;
		InputDB _rawentries;
		InputDB _rawDB;
		std::string _dbPath;
		void extractAndInsertEntry(std::string &line);
		void extractAndInsertDBField(std::string &line);
		//std::time_t getDate(std::string line);
		t_date setDate(std::string &line);
		float getAmount(std::string line);
		float findExchangeRate(std::time_t time);
};

std::ostream &operator<<(std::ostream &cout, const t_date &date);
bool operator<(const t_date &k1, const t_date &k2);

#endif

