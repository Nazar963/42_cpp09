#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <dirent.h> //? to open the file ending with csv inside the ./

class BitcoinExchange
{
	public:
		std::map<int, float>	loco;
		BitcoinExchange();

		void			checkAc(int ac, char **av);
		void			openDir();
		bool			isValidDate(int date);
		std::string		formatDouble(double d);

		class LowNumberOfArguments : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Wrong Number Of Arguments"); }
		};
		class FileNotOpen : public std::exception
		{
			public: const char* what() const throw() { return ("Error: File Didn't Open"); }
		};
		class FileEmpty : public std::exception
		{
			public: const char* what() const throw() { return ("Error: File is empty no key | value pairs were found"); }
		};
		class DirNotOpen : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Not able to open currect directory"); }
		};
		class WrongFileHeader : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Wrong File Formating"); }
		};
		class InvalidDate : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Invalid date format"); }
		};
		class InvalidValue : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Invalid value format"); }
		};

		~BitcoinExchange();
};


#endif