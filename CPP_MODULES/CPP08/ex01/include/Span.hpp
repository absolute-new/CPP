#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <vector>

namespace s42
{
class Span
{
private:
	std::vector<int>	vec_;
	unsigned int		maxSize_;
public:
	Span(void);
	Span(const unsigned int maxSize);
	Span(const Span& other);
	~Span(void);

	Span& operator=(const Span& other);

	void	addNumber(const int value);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;
};
} // namespace 42

#endif
