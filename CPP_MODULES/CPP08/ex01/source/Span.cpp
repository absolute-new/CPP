#include "Span.hpp"
#include "fastSort.hpp"
#include <stdexcept>
#include <climits>

s42::Span::Span(void) : maxSize_(0) {}

s42::Span::Span(const unsigned int maxSize) : maxSize_(maxSize) {}

s42::Span::Span(const Span& other) : vec_(other.vec_),
	maxSize_(other.maxSize_) {}

s42::Span::~Span(void) {}

s42::Span& s42::Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxSize_ = other.maxSize_;
		vec_ = other.vec_;
	}
	return (*this);
}

void s42::Span::addNumber(const int value)
{
	if (vec_.size() >= maxSize_)
		throw std::runtime_error("Span is already full");
	vec_.push_back(value);
}

int s42::Span::shortestSpan(void) const
{
	int	minSpan;
	int	span;

	if (vec_.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::vector<int> copy(vec_);
	quickSort(copy);
	minSpan = INT_MAX;
	for (size_t i = 1; i < copy.size(); ++i)
	{
		span = copy[i] - copy[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int s42::Span::longestSpan(void) const
{
	int	min;
	int	max;

	if (vec_.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	min = vec_[0];
	max = vec_[0];
	for (size_t i = 1; i < vec_.size(); ++i)
	{
		if (vec_[i] < min)
			min = vec_[i];
		if (vec_[i] > max)
			max = vec_[i];
	}
	return (max - min);
}
