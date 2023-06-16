#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class RPN
{
	private:
			std::list<int> _loco;
	public:
		RPN();

		void	check_number_arguments(int ac);
		void	reversePolishNotation(char **av);

		class LowNumberOfArguemts : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Wrong Number Of Arguments"); }
		};
		class InvalidSize : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Invalid Size"); }
		};
		class UnkownCharacter : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Unknown Character"); }
		};
		class InvalidDivision : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Division by 0"); }
		};

		~RPN();
};

#endif