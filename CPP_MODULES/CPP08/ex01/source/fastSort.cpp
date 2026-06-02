#include "fastSort.hpp"
#include <stack>
#include <iterator>

using Iterator = std::vector<int>::iterator;

static Iterator partition(Iterator left, Iterator right)
{
	auto mid = left;
	std::advance(mid, std::distance(left, right) / 2);
	if (*mid < *left)
		std::iter_swap(mid, left);
	if (*right < *left)
		std::iter_swap(right, left);
	if (*mid < *right)
		std::iter_swap(mid, right);
	int pivot = *right;
	auto i = left;
	for (auto j = left; j != right; j++)
	{
		if (*j <= pivot)
		{
			std::iter_swap(i, j);
			i++;
		}
	}
	std::iter_swap(i, right);
	return (i);
}


void 	IterQuickSort(Iterator begin, Iterator end)
{
	if (begin == end)
		return ;
	std::stack<std::pair<Iterator, Iterator>> st;
	st.push({begin, std::prev(end)});
	while (!st.empty())
	{
		auto [left, right] = st.top();
		st.pop();
		if (left >= right)
			continue ;		
		if (std::distance(left, right) < 16)
		{
			for (auto i = std::next(left); i <= right; ++i)
			{
				auto key = *i;
				auto j = i;
				while (j != left && *std::prev(j) > key)
				{
					*j = *std::prev(j);
					--j;
				}
				*j = key;
			}
			continue ;
		}
		Iterator pivot = partition(left, right);
		if (std::distance(left, pivot) > std::distance(pivot, right))
		{
			st.push({left, std::prev(pivot)});
			st.push({std::next(pivot), right});
		}
		else
		{
			st.push({std::next(pivot), right});
			st.push({left, std::prev(pivot)});
		}
	}	
}

void s42::quickSort(std::vector<int>& arr)
{
	if (arr.empty())
		return ;
	IterQuickSort(arr.begin(), arr.end());
}
