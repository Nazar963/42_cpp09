#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

void	BitcoinExchange::checkAc(int ac, char **av)
{
	if (ac != 2)
		throw BitcoinExchange::LowNumberOfArguments();
	else
	{
		std::ifstream file(av[1]);
		if (!file.is_open()) throw BitcoinExchange::FileNotOpen();
		else file.close();
	}
}

void	BitcoinExchange::openDir()
{
	DIR						*dir;
	struct dirent			*ent;
	std::string				fileName;
	std::string				line;
	std::string				key;
	long int				new_key;
	std::string				number;
	float					num;

	if ((dir = opendir("./")) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			fileName = ent->d_name;
			if(fileName.size() > 4 && fileName.substr(fileName.size() - 4) == ".csv")
			{
				std::ifstream file(fileName.c_str());
				if (!file.is_open())
				{
					closedir(dir);
					throw BitcoinExchange::FileNotOpen();
					break ;
				}
				std::getline(file, line);
				if (line.compare("date,exchange_rate") != 0)
				{
					closedir(dir);
					throw (BitcoinExchange::WrongFileHeader());
					break ;
				}

				while (std::getline(file, line))
				{
					//! ------------------------------ control date ------------------------------ */
					for(int i = 0; line[i] != ','; i++)
						key += line[i];
					key.erase(std::remove(key.begin(), key.end(), '-'), key.end());
					std::istringstream iss_key(key);
					iss_key >> new_key;
					if (new_key == 0)
					{
						key.clear();
						continue;
					}
					//! ------------------------------ control value ----------------------------- */
					for(size_t i = line.find(',') + 1; i < line.size(); i++)
						number += line[i];
					std::istringstream iss_num(number);
					iss_num >> num;
					this->loco[new_key] = num;
					key.clear();
					number.clear();
				}
				file.close();
				if (this->loco.empty()) throw BitcoinExchange::FileEmpty();
				break;
			}
		}
		closedir(dir);
		if (ent == NULL)
			throw BitcoinExchange::DirNotOpen();
	}
	else
		throw BitcoinExchange::DirNotOpen();
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