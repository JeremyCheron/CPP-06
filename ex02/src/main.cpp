/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 06:56:30 by jcheron           #+#    #+#             */
/*   Updated: 2025/04/07 06:58:30 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Base.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void) {
	Base	*ptr = generate();

	std::cout << "Using pointer   : ";
	identify(ptr);

	std::cout << "Using reference : ";
	identify(*ptr);

	delete ptr;
	return (0);
}
