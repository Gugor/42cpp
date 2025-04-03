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

class BitcoinExange
{
	public:
		BitcoinExange(const std::string bd);
		BitcoinExange(const BitcoinExange &other);
		BitcoinExange &operator=(const BitcoinExange &bitcoinexange);
		~BitcoinExange(void);
		const std::map<std::time_t, float> getEntries(void) const; 
		void fetchEntries(const std::string &entriesFile);
		void printEntries(void);

		class WrongEntryFileFormatException : public std::exception
		{
			public:
				WrongEntryFileFormatException(std::string msg);
				virtual const char *what(void) const throw();
				virtual ~WrongEntryFileFormatException(void) throw();
			protected:
				std::string _msg;
		};


	private:
		BitcoinExange(void);
		typedef std::map<std::time_t, float> InputDB;
		InputDB _entries;
		std::string bd;
		void extractAndInsertEntry(std::string &line);
		std::time_t getDate(std::string line, std::size_t separator);
		float getAmount(std::string line, std::size_t separator);
		float findExangeRate(std::time_t time);
};

#endif

