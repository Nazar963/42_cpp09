#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		
		void			checkAc(int ac);
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

		~BitcoinExchange();
};


#endif