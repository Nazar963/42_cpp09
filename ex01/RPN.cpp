#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}

void	RPN::check_number_arguments(int ac)
{
	if (ac != 2) throw RPN::LowNumberOfArguemts();
}

void	RPN::reversePolishNotation(char **av)
{
	for (size_t i = 0; av[1][i] != '\0'; ++i)
	{
		if (av[1][i] >= '0' && av[1][i] <= '9')
		{
			_loco.push_back(av[1][i] - '0');
		}
		else if (av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '*' || av[1][i] == '/')
		{
			if (_loco.size() < 2)
			{
				throw RPN::InvalidSize();
				return ;
			}
			int second_number = _loco.back(); _loco.pop_back();
			int first_number = _loco.back(); _loco.pop_back();
			int result;
			if (av[1][i] == '+')
				result = first_number + second_number;
			else if (av[1][i] == '-')
				result = first_number - second_number;
			else if (av[1][i] == '*')
				result = first_number * second_number;
			else if (av[1][i] == '/')
			{
				if (second_number == 0)
				{
					throw RPN::InvalidDivision();
					return ;
				}
				result = first_number / second_number;
			}
			_loco.push_back(result);
		}
		else if (av[1][i] != ' ')
		{
			throw RPN::UnkownCharacter();
			return ;
		}
	}
	if (_loco.size() != 1)
	{
		throw RPN::InvalidSize();
		return ;
	}
	std::cout << _loco.back() << std::endl;
}