#include "../includes/ScalarConverter.hpp"

static int	isSpecial(const std::string &str) {
	return (str == "nan" || str == "nanf"
		|| str == "-inf" || str == "+inf"
		|| str == "-inff" || str == "+inff");
}

static int	isChar(const std::string &str) {
	return (str.length() == 1 && !isdigit(str[0]));
}

static int	isInt(const std::string &str) {
	int	i = 0;
	bool	sign = false;
	if (str[i] == '-' || str[i] == '+') {
		sign = true;
		i++;
	}
	while ((str[i] && str.length() > 0 && str.length() < 12)
			|| (str[i] && !sign && str.length() < 11 && str.length() > 0)) {
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	isFloat(const std::string &str, size_t &dot) {
	for (int j = dot - 1; j >= 0; j--) {
		if (!isdigit(str[j]) && j != 0)
			return (0);
		if (!isdigit(str[j]) && j == 0 && str[j] != '-' && str[j] != '+')
			return (0);
	}
	for (size_t i = dot +1; i < str.length(); i++) {
		if (!isdigit(str[i]) && str[i] != 'f')
			return (0);
		if (str[i] == 'f' && i != str.length() - 1) {
			return (0);
		}
	}
	return (1);
}

e_type	wich(const std::string &str) {
	size_t	dot = str.find('.');
	size_t	f = str.find('f');

	if (dot == std::string::npos) {
		if (isSpecial(str))
			return (SPECIAL);
		if (isChar(str))
			return (CHAR);
		if (isInt(str))
			return (INT);
	}
	else if (f != std::string::npos && dot != std::string::npos) {
		if (isFloat(str, dot))
			return (FLOAT);
	}
	else if (dot != std::string::npos && f == std::string::npos)
		return (DOUBLE);
	return (INVALID);
}
