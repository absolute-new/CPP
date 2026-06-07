#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>

namespace s42
{
class PmergeMe
{
private:
	std::vector<int>	vec_;
	std::list<int>		lst_;
public:
	PmergeMe(void);
	~PmergeMe(void);

	void	parseArguments(int argc, char *argv[]);
	void	printBefore(void) const;
	void	printAfter(void) const;
	void	sortAndMeasure(void);
private:
	void	sortVector_(std::vector<int>& vec);
	void	sortList_(std::list<int>& lst);
};
}
#endif
