/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:56:01 by jcheron           #+#    #+#             */
/*   Updated: 2025/04/03 08:10:00 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <limits>
#include <cmath>

#define MIN_INT std::numeric_limits<int>::min()
#define MAX_INT std::numeric_limits<int>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_DOUBLE std::numeric_limits<double>::min()
#define MAX_DOUBLE std::numeric_limits<double>::max()

enum e_type
{
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID = -1
};

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &other);

	public:

		static void	convert(const std::string &str);

};

e_type	wich(const std::string &str);
void	convertChar(char c);
void	convertInt(const std::string &str);
void	convertFloat(const std::string &str);
void	convertDouble(const std::string &str);
void	printSpecial(const std::string &str);
