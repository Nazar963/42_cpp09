#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange	levi;

	//! -------------------------------------------------------------------------- */
	//!                               check arguments                              */
	//! -------------------------------------------------------------------------- */
	try
	{
		levi.checkAc(ac, av);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}

	//! -------------------------------------------------------------------------- */
	//!                            open csv and process                            */
	//! -------------------------------------------------------------------------- */
	try
	{
		levi.openDir();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}

	/* -------------------------------------------------------------------------- */
	std::string				key;
	long int				new_key;
	std::string				number;
	float					num;
	std::string				what;
	std::ifstream			input(av[1]);

	std::getline(input, what);
	try
	{
		if (what.compare("date | value") != 0)
			throw BitcoinExchange::WrongFileHeader();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	while (std::getline(input, what))
	{
		
		//! ------------------------------ control date ------------------------------ */
		for(unsigned int i = 0; what[i] != '|' && i < what.size(); i++)
			key += what[i];
		key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
		try
		{
			if (key.size() != 10)
				throw BitcoinExchange::InvalidDate();
			for (unsigned long i = 0; i < key.size(); i++)
			{
				if (i == 4 || i == 7)
				{
					if (key[i] != '-')
						throw BitcoinExchange::InvalidDate();
				}
			}
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			return (0);
		}
		
		key.erase(std::remove(key.begin(), key.end(), '-'), key.end());
		std::istringstream iss_key_n(key);
		iss_key_n >> new_key;
		if (new_key == 0 && what[0] != '0')
		{
			key.clear();
			continue;
		}
		//! ------------------------------ control value ----------------------------- */
		for(size_t i = what.find('|') + 1; i < what.size(); i++)
			number += what[i];

		std::istringstream iss_num_n(number);
		try
		{
			if (what.find('|'))
				if (!(iss_num_n >> num))
					throw BitcoinExchange::InvalidValue();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			levi.loco.clear();
			return (0);
		}
		
		if (levi.loco[new_key])
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
			float sol = levi.loco[new_key] * num;
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
			while (!levi.loco[new_key])
				new_key--;
			float sol = levi.loco[new_key] * num;
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