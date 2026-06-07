#include "PmergeMe.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <climits>
#include <time.h>
#include <cstdlib>
#include <chrono>

s42::PmergeMe::PmergeMe(void) {}

s42::PmergeMe::~PmergeMe(void) {}

void	s42::PmergeMe::parseArguments(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::string	arg = argv[i];
		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!std::isdigit(arg[j]))
				throw std::runtime_error("Error: invalid argument");
		}
		long	num = std::atol(arg.c_str());
		if (num < 0 || num > INT_MAX)
			throw std::runtime_error("Error: number out of range");
		vec_.push_back(static_cast<int>(num));
		lst_.push_back(static_cast<int>(num));
	}
}

void	s42::PmergeMe::sortAndMeasure(void)
{
	auto	start = std::chrono::high_resolution_clock::now();
	sortVector_(vec_);
	auto	end = std::chrono::high_resolution_clock::now();
	double timeVec = std::chrono::duration<double, std::micro>(end - start).count();

	start = std::chrono::high_resolution_clock::now();
	sortList_(lst_);	
	end = std::chrono::high_resolution_clock::now();
	double	timeLst = std::chrono::duration<double, std::micro>(end - start).count();
	this->printAfter();
	std::cout << "Time to process a range of " << vec_.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << lst_.size()
		<< " elements with std::list : " << timeLst << " us" << std::endl;	
}

void	s42::PmergeMe::printAfter(void) const
{
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = vec_.begin();
		it != vec_.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != vec_.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	s42::PmergeMe::printBefore(void) const
{
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = vec_.begin();
		it != vec_.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != vec_.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	s42::PmergeMe::sortVector_(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return ;
	std::vector< std::pair<int, int> >	pairs;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
		pairs.push_back({vec[i], vec[i + 1]});
	}
	int	leftover = (vec.size() % 2 == 1) ? vec.back() : -1;
	
	std::vector<int>	bigs;
	for (size_t i = 0; i < pairs.size(); ++i)
		bigs.push_back(pairs[i].second);
	sortVector_(bigs);
	std::vector<int>	smalls;
	for (size_t i = 0; i < pairs.size(); ++i)
		smalls.push_back(pairs[i].first);
	
	for (size_t i = pairs.size(); i > 0; --i)
	{
		int	small = smalls[i - 1];
		std::vector<int>::iterator pos = std::lower_bound(bigs.begin(),
			bigs.end(), small);
		bigs.insert(pos, small);
	}
	if (leftover != -1)
	{
		std::vector<int>::iterator pos = std::lower_bound(bigs.begin(),
			bigs.end(), leftover);
		bigs.insert(pos, leftover);
	}
	vec = bigs;
}

void	s42::PmergeMe::sortList_(std::list<int>& lst)
{
	if (lst.size() <= 1)
		return ;
	std::list< std::pair<int, int> >	pairs;
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end())
	{
		int	first = *it;
		++it;
		if (it == lst.end())
			break ;
		int	second = *it;
		++it;
		if (first > second)
			std::swap(first, second);
		pairs.push_back({first, second});
	}
	int	leftover = (lst.size() % 2 == 1) ? lst.back(): -1;
	std::list<int>	bigs;
	for (std::list<std::pair<int, int> >::iterator pit = pairs.begin();
		pit != pairs.end(); ++pit)
		bigs.push_back(pit->second);
	sortList_(bigs);
	std::list<int>	smalls;
	for (std::list<std::pair<int, int> >::iterator pit = pairs.begin();
		pit != pairs.end(); ++pit)
		smalls.push_back(pit->first);
	for (size_t i = pairs.size(); i > 0; --i)
	{
		int	small = smalls.back();
		smalls.pop_back();
		std::list<int>::iterator pos = bigs.begin();
		while (pos != bigs.end() && *pos < small)
			pos++;
		bigs.insert(pos, small);		 
	}
	if (leftover != -1)
	{
		std::list<int>::iterator pos = bigs.begin();
		while (pos != bigs.end() && *pos < leftover)
			pos++;
		bigs.insert(pos, leftover);		
	}
	lst = bigs;
}
