/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:17:35 by jcheron           #+#    #+#             */
/*   Updated: 2025/04/03 08:10:36 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

void	ScalarConverter::convert(const std::string &str)
{
	e_type	type = wich(str);

	switch (type)
	{
	case INVALID:
		std::cout << "Invalid input" << std::endl;
		break;
	case SPECIAL:
		printSpecial(str);
		break;
	case CHAR:
		convertChar(str[0]);
		break;
	case INT:
		convertInt(str);
		break;
	case FLOAT:
		convertFloat(str);
		break;
	case DOUBLE:
		convertDouble(str);
		break;
	default:
		break;
	}
}
