/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 06:40:01 by jcheron           #+#    #+#             */
/*   Updated: 2025/04/07 06:44:49 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"

int	main(void) {
	Data	original;

	original.id = 42;
	original.name = "Test Object";

	uintptr_t	raw = Serializer::serialize(&original);
	Data		*deserialized = Serializer::deserialize(raw);

	std::cout << "Original Address    : " << &original << std::endl;
	std::cout << "Deserialized Adress : " << deserialized << std::endl;

	if (deserialized == &original)
		std::cout << "✅ Pointers match!" << std::endl;
	else
		std::cout << "❌ Pointers don't match!" << std::endl;

	std::cout << "Deserialized Data : id = " << deserialized->id
		<< ", name = " << deserialized->name << "." << std::endl;

	return (0);
}
