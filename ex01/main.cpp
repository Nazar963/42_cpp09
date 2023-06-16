#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN	zoro;

	try
	{
		zoro.check_number_arguments(ac);
	}
	catch (RPN::LowNumberOfArguemts& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}

	try
	{
		zoro.reversePolishNotation(av);
	}
	catch (RPN::InvalidDivision& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	catch (RPN::UnkownCharacter& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	catch (RPN::InvalidSize& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}

	return (0);
}