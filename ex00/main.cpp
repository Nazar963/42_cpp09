#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange	levi;
	try
	{
		levi.checkAc(ac);
	}
	catch (BitcoinExchange::LowNumberOfArguments& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::ifstream file("data.csv");
	try
	{
		if (!file.is_open()) throw BitcoinExchange::FileNotOpen();

	}
	catch (BitcoinExchange::FileNotOpen& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::map<int, float> loco;
	std::string line;
	std::string	key;
	long int	new_key;
	std::string number;
	float num;
	while (std::getline(file, line))
	{
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
		for(size_t i = line.find(',') + 1; i < line.size(); i++)
			number += line[i];
		std::istringstream iss_num(number);
		iss_num >> num;
		loco[new_key] = num;
		key.clear();
		number.clear();
	}
	file.close();
	try
	{
		if (loco.empty()) throw BitcoinExchange::FileEmpty();
	}
	catch (BitcoinExchange::FileEmpty& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::string what;
	std::ifstream input(av[1]);
	try
	{
		if (!input.is_open()) throw BitcoinExchange::FileNotOpen();

	}
	catch (BitcoinExchange::FileNotOpen& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	while (std::getline(input, what))
	{
		for(int i = 0; what[i] != '|'; i++)
			key += what[i];
		key.erase(std::remove(key.begin(), key.end(), '-'), key.end());
		std::istringstream iss_key_n(key);
		iss_key_n >> new_key;

		if (new_key == 0 && what[0] != '0')
		{
			key.clear();
			continue;
		}
		for(size_t i = what.find('|') + 1; i < what.size(); i++)
			number += what[i];
		std::istringstream iss_num_n(number);
		iss_num_n >> num;

		if (loco[new_key])
		{
			if (num < 0)
			{
				std::cout << "ERROR: not a positive number." << std::endl;
				key.clear();
				number.clear();
				continue;
			}
			else if (num > 1000)
			{
				std::cout << "ERROR: too large a number." << std::endl;
				key.clear();
				number.clear();
				continue;
			}
			float sol = loco[new_key] * num;
			std::ostringstream oss;
			oss << new_key;
			std::string new_date = oss.str();
			new_date.insert(4, "-");
			new_date.insert(7, "-");
			std::cout << new_date << " => " << num << " = " << levi.formatDouble(sol) << std::endl;
		}
		else
		{
			if (!levi.isValidDate(new_key))
			{
				if (new_key == 0)
				{
					key.clear();
					number.clear();
					continue;
				}
				std::ostringstream osss;
				osss << new_key;
				std::string new_date = osss.str();
				new_date.insert(4, "-");
				new_date.insert(7, "-");
				std::cout << "ERROR: bad input => " << new_date << std::endl;
				key.clear();
				number.clear();
				continue;
			}
			if (num < 0)
			{
				std::cout << "ERROR: not a positive number." << std::endl;
				key.clear();
				number.clear();
				continue;
			}
			else if (num > 1000)
			{
				std::cout << "ERROR: too large a number." << std::endl;
				key.clear();
				number.clear();
				continue;
			}
			int old_key = new_key;
			while (!loco[new_key])
				new_key--;
			float sol = loco[new_key] * num;
			std::ostringstream oss;
			oss << old_key;
			std::string new_date = oss.str();
			new_date.insert(4, "-");
			new_date.insert(7, "-");
			std::cout << new_date << " => " << num << " = " << levi.formatDouble(sol) << std::endl;
		}
		key.clear();
		number.clear();
	}
	input.close();
}