#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

# include <stack>
# include <string>

namespace s42
{
class RPN
{
private:
	std::stack<int>	stack_;
public:
	RPN(void);
	~RPN(void);

	int		calculate(const std::string& expression);
private:
	bool	isOperator(const std::string& token) const;
	bool	isNumber(const std::string& token) const;
	void	performOperator(const std::string& op);
};
} // namespace 42

#endif
