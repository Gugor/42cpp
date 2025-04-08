#ifndef BITCOINEXANGE_H 
# define BITCOINEXANGE_H 

# include <iostream>
# include <ctime>
# include <cstring>
# include <fstream>
# include <algorithm>
# include <map>
# include <exception>

#define ENTRY_SEPARATOR "|"
#define DB_SEPARATOR ","

class BitcoinExange
{
	public:
		BitcoinExange(const std::string bd);
		BitcoinExange(const BitcoinExange &other);
		BitcoinExange &operator=(const BitcoinExange &bitcoinexange);
		~BitcoinExange(void);
		const std::map<std::time_t, float> getEntries(void) const; 
		const std::string &getBDPath(void) const;
		void fetchEntries(const std::string &input);
		void fetchDB(void);
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
		BitcoinExange(void);
		typedef std::map<std::time_t, float> InputDB;
		typedef std::map<std::string, std::string> RawInputDB;
		typedef std::map<std::string, std::string> RawDB;
		InputDB _entries;
		RawInputDB _rawentries;
		RawDB _rawDB;
		std::string _entriesPath;
		void extractAndInsertEntry(std::string &line);
		void extractAndInsertDBField(std::string &line);
		std::time_t getDate(std::string line, std::size_t separator, std::string &out);
		float getAmount(std::string line, std::size_t separator);
		float findExangeRate(std::time_t time);
};

#endif

