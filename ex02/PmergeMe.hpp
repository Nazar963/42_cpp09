#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>

typedef std::vector<int>::iterator iterator;

class PmergeMe
{
	public:
		PmergeMe();

		void	controlAc(int ac);
		void	controlLoco(std::vector<int>& loco, int ac, char **av);

		void	sortLastNumber(std::vector<int>& loco);
		void	sortPair(std::vector<int>& loco, int i, int j);
		void	fordJohnsonSort(std::vector<int>& loco);

		void	sortLastNumberDeque(std::deque<int>& zoro);
		void	sortPairDeque(std::deque<int>& zoro, int i, int j);
		void	fordJohnsonSortDeque(std::deque<int>& zoro);

		~PmergeMe();
		class LowNumberOfArguemts : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Wrong Number Of Arguments"); }
		};

		class NegativeNumber : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Negative Number Present"); }
		};

		class LowNumberOfElements : public std::exception
		{
			public: const char* what() const throw() { return ("Error: Low Number Of Elements"); }
		};
};

#endif