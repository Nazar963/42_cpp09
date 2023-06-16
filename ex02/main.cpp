#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	levi;

	try
	{
		levi.controlAc(ac);
	}
	catch (PmergeMe::LowNumberOfArguemts& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::vector<int>	loco;
	try
	{
		levi.controlLoco(loco, ac, av);
	}
	catch (PmergeMe::NegativeNumber& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	catch (PmergeMe::LowNumberOfElements& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
	std::cout << "Before:  ";
	for(iterator it = loco.begin(); it != loco.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::clock_t start = std::clock();
	levi.fordJohnsonSort(loco);
	std::clock_t end = std::clock();
	std::cout << "After:   ";
	for(std::vector<int>::iterator it = loco.begin(); it != loco.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::deque<int>		zoro;
	for (int i = 1; i < ac; i++)
		zoro.push_back(atoi(av[i]));
	std::clock_t startDeque = std::clock();
	levi.fordJohnsonSortDeque(zoro);
	std::clock_t endDeque = std::clock();
	double duration = 1000.0 * (end-start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << (ac -  1) << " elements with std::vector :  " << duration << "ms\n";
	double durationDeque = 1000.0 * (endDeque-startDeque) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << (ac -  1) << " elements with std::deque :  " << durationDeque << "ms\n";

	return (0);
}