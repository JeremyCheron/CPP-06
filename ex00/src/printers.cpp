/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:37:52 by jcheron           #+#    #+#             */
/*   Updated: 2025/04/07 06:33:36 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static void	printChar(char c)
{
	if (std::isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}


static void printInt(long l)
{
	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else
		printChar(static_cast<char>(l));
	std::cout << "int: ";
	if (l < MIN_INT || l > MAX_INT)
		std::cout << "impossible" << std::endl ;
	else
		std::cout << static_cast<int>(l) << std::endl;
	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

static void	printFloat(double f) {
	bool isWhole = std::fabs(f - static_cast<int>(f)) < 1e-10;
	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else
		printChar(static_cast<char>(f));
	std::cout << "int: ";
	if (f < MIN_INT || f > MAX_INT || !isWhole)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: ";
	if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(f) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	convertInt(const std::string &str)
{
	printInt(std::atol(str.c_str()));
}

void	convertFloat(const std::string &str) {
	printFloat(std::atof(str.c_str()));
}

void convertDouble(const std::string &str) {
	printFloat(std::atof(str.c_str()));
}

void	convertChar(char c) {
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";
}

void	printSpecial(const std::string &str) {
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (str == "+inf" || str == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	} else if (str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
