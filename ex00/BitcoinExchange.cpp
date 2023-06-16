#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

void	BitcoinExchange::checkAc(int ac)
{
	if (ac != 2) throw BitcoinExchange::LowNumberOfArguments();
}

bool	BitcoinExchange::isValidDate(int date)
{
	if (date < 20090102 || date == 0) return false;
	int year = date / 10000;
	int month = (date / 100) % 100;
	int day = date % 100;

	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;
	if (month == 2)
	{
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			if (day > 29) return false;
		}
		else
			if (day > 28) return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30) return false;

	return true;
}

std::string	BitcoinExchange::formatDouble(double d)
{
	std::ostringstream oss;
	oss << std::fixed << d;
	std::string str = oss.str();
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);
	if (*(str.end() - 1) == '.')
		str.erase(str.end() - 1);
	return str;
}