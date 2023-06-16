#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

/* -------------------------------------------------------------------------- */
/*                                 Preparation                                */
/* -------------------------------------------------------------------------- */

void	PmergeMe::controlAc(int ac)
{
	if (ac == 1) throw PmergeMe::LowNumberOfArguemts();
}

void	PmergeMe::controlLoco(std::vector<int>& loco, int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		if (atoi(av[i]) < 0)
		{
			throw PmergeMe::NegativeNumber();
			return ;
		}
		loco.push_back(atoi(av[i]));
	}
	if (loco.size() <= 1) throw PmergeMe::LowNumberOfElements();
}

/* -------------------------------------------------------------------------- */
/*                                   Vector                                   */
/* -------------------------------------------------------------------------- */

void	PmergeMe::sortLastNumber(std::vector<int>& loco)
{
	int lastNumber = loco.back();
	loco.pop_back();
	size_t i;
	for (i = 0; i < loco.size(); i++)
	{
		if (lastNumber < loco[i])
		{
			loco.insert(loco.begin() + i, lastNumber);
			break;
		}
	}
	if (i == (loco.size()))
		loco.push_back(lastNumber);
}

void	PmergeMe::sortPair(std::vector<int>& loco, int i, int j)
{
	if (loco[i] > loco[j]) std::swap(loco[i], loco[j]);
}

void	PmergeMe::fordJohnsonSort(std::vector<int>& loco)
{
	int lastNumber;
	bool odd = false;
	for (size_t i = 0; i < loco.size() - 1; i += 2)
		sortPair(loco, i, i + 1);
	if (loco.size() % 2 != 0)
	{
		lastNumber = loco.back();
		loco.pop_back();
		odd = true;
	}
	std::vector<int> firstPart;
	std::vector<int> secondPart;
	for (size_t i = 0; i != loco.size(); i += 2)
	{
		firstPart.push_back(loco[i]);
		secondPart.push_back(loco[i + 1]);
	}
	std::vector<int> firstPartSorted;
	for (size_t i = 0; i < firstPart.size(); i++)
	{
		size_t insertPos = firstPartSorted.size();
		for (size_t j = 0; j < firstPartSorted.size(); j++)
		{
			if (firstPart[i] < firstPartSorted[j])
			{
				insertPos = j;
				break;
			}
		}
		firstPartSorted.insert(firstPartSorted.begin() + insertPos, firstPart[i]);
	}
	for (size_t i = 0; i < secondPart.size(); i++)
	{
		size_t insertPos = firstPartSorted.size();
		for (size_t j = 0; j < firstPartSorted.size(); j++)
		{
			if (secondPart[i] < firstPartSorted[j])
			{
				insertPos = j;
				break;
			}
		}
		firstPartSorted.insert(firstPartSorted.begin() + insertPos, secondPart[i]);
	}
	if (odd == true)
	{
		odd = false;
		firstPartSorted.push_back(lastNumber);
		sortLastNumber(firstPartSorted);
	}
	loco.clear();
	loco = firstPartSorted;
}

/* -------------------------------------------------------------------------- */
/*                                    Deque                                   */
/* -------------------------------------------------------------------------- */

void	PmergeMe::sortLastNumberDeque(std::deque<int>& zoro)
{
	int lastNumber = zoro.back();
	zoro.pop_back();
	size_t i;
	for (i = 0; i < zoro.size(); i++)
	{
		if (lastNumber < zoro[i])
		{
			zoro.insert(zoro.begin() + i, lastNumber);
			break;
		}
	}
	if (i == (zoro.size()))
		zoro.push_back(lastNumber);
}

void	PmergeMe::sortPairDeque(std::deque<int>& zoro, int i, int j)
{
	if (zoro[i] > zoro[j]) std::swap(zoro[i], zoro[j]);
}

void	PmergeMe::fordJohnsonSortDeque(std::deque<int>& zoro)
{
	int lastNumber;
	bool odd = false;
	for (size_t i = 0; i < zoro.size() - 1; i += 2)
		sortPairDeque(zoro, i, i + 1);
	if (zoro.size() % 2 != 0)
	{
		lastNumber = zoro.back();
		zoro.pop_back();
		odd = true;
	}
	std::deque<int> firstPart;
	std::deque<int> secondPart;
	for (size_t i = 0; i != zoro.size(); i += 2)
	{
		firstPart.push_back(zoro[i]);
		secondPart.push_back(zoro[i + 1]);
	}
	std::deque<int> firstPartSorted;
	for (size_t i = 0; i < firstPart.size(); i++)
	{
		size_t insertPos = firstPartSorted.size();
		for (size_t j = 0; j < firstPartSorted.size(); j++)
		{
			if (firstPart[i] < firstPartSorted[j])
			{
				insertPos = j;
				break;
			}
		}
		firstPartSorted.insert(firstPartSorted.begin() + insertPos, firstPart[i]);
	}
	for (size_t i = 0; i < secondPart.size(); i++)
	{
		size_t insertPos = firstPartSorted.size();
		for (size_t j = 0; j < firstPartSorted.size(); j++)
		{
			if (secondPart[i] < firstPartSorted[j])
			{
				insertPos = j;
				break;
			}
		}
		firstPartSorted.insert(firstPartSorted.begin() + insertPos, secondPart[i]);
	}
	if (odd == true)
	{
		odd = false;
		firstPartSorted.push_back(lastNumber);
		sortLastNumberDeque(firstPartSorted);
	}
	zoro.clear();
	zoro = firstPartSorted;
}