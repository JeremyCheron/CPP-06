#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

bool ScalarConverter::isSpecial(const std::string& str) {
	return (str == "nan" || str == "nanf" ||
			str == "+inf" || str == "+inff" ||
			str == "-inf" || str == "-inff");
}

bool ScalarConverter::isChar(const std::string& str) {
	if (str.length() != 1)
		return false;
	return !isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string& str) {
	if (str.empty())
		return false;

	size_t i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;

	if (i == str.length())
		return false;

	for (; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}

	return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
	if (str.empty() || str[str.length() - 1] != 'f')
		return false;

	std::string withoutF = str.substr(0, str.length() - 1);
	if (withoutF.empty())
		return false;

	size_t dotCount = 0;
	size_t i = 0;

	if (withoutF[0] == '-' || withoutF[0] == '+')
		i++;

	if (i == withoutF.length())
		return false;

	for (; i < withoutF.length(); i++) {
		if (withoutF[i] == '.') {
			dotCount++;
			if (dotCount > 1)
				return false;
		}
		else if (!isdigit(withoutF[i]))
			return false;
	}

	return dotCount == 1;
}

bool ScalarConverter::isDouble(const std::string& str) {
	if (str.empty())
		return false;

	size_t dotCount = 0;
	size_t i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;

	if (i == str.length())
		return false;

	for (; i < str.length(); i++) {
		if (str[i] == '.') {
			dotCount++;
			if (dotCount > 1)
				return false;
		}
		else if (!isdigit(str[i]))
			return false;
	}

	return dotCount == 1;
}

void ScalarConverter::printChar(char c) {
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printSpecial(const std::string& str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str) {
	if (str.empty()) {
		std::cout << "Error: empty string" << std::endl;
		return;
	}

	if (isSpecial(str)) {
		printSpecial(str);
		return;
	}

	if (isChar(str)) {
		char c = str[0];
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
		return;
	}

	if (isInt(str)) {
		long l = strtol(str.c_str(), NULL, 10);
		if (l < INT_MIN || l > INT_MAX) {
			std::cout << "Error: integer overflow" << std::endl;
			return;
		}
		int i = static_cast<int>(l);
		printChar(static_cast<char>(i));
		printInt(i);
		printFloat(static_cast<float>(i));
		printDouble(static_cast<double>(i));
		return;
	}

	if (isFloat(str)) {
		std::string withoutF = str.substr(0, str.length() - 1);
		float f = strtof(withoutF.c_str(), NULL);
		if (f < -FLT_MAX || f > FLT_MAX) {
			std::cout << "Error: float overflow" << std::endl;
			return;
		}
		printChar(static_cast<char>(f));
		printInt(static_cast<int>(f));
		printFloat(f);
		printDouble(static_cast<double>(f));
		return;
	}

	if (isDouble(str)) {
		double d = strtod(str.c_str(), NULL);
		if (d < -DBL_MAX || d > DBL_MAX) {
			std::cout << "Error: double overflow" << std::endl;
			return;
		}
		printChar(static_cast<char>(d));
		printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble(d);
		return;
	}

	std::cout << "Error: invalid input" << std::endl;
}
