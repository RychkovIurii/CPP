/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:21:00 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/02 11:34:56 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

/* Notes. If we will try to deserialize deleted pointer, it will cause
undefined behavior. */

int	main( void ) {
	Data data;
	data.index = 42;
	data.name = "irychkov";

	std::cout << "==== Original data ====" << std::endl;
	std::cout << "data: {" << data.index << "}, {" << data.name
			<< "}" << std::endl;
	std::cout << "address: " << &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	std::cout << "\n==== Deserialized data ====" << std::endl;
	Data* deserialized_data = Serializer::deserialize(raw);
	std::cout << "Deserialized data: {" << deserialized_data->index << "}, {"
			<< deserialized_data->name << "}" << std::endl;
	std::cout << "Deserialized address: " << deserialized_data << std::endl;

	std::cout << "\n==== Check pointers ====" << std::endl;
	if (&data != deserialized_data) {
		std::cout << "Deserialization failed: pointers do not match! UNEXPECTED!"
			<< std::endl;
	} else {
		std::cout << "Deserialization successful: Success!" << std::endl;
	}
	
	try {
		std::cout << "\n==== Copy data ====" << std::endl;
		Data *copy = new Data(data);
		std::cout << "Copy data: {" << copy->index << "}, {" << copy->name
				<< "}" << std::endl;
		std::cout << "Copy address: " << copy << std::endl;
		uintptr_t serialized_copy = Serializer::serialize(copy);
		uintptr_t serialized_data = Serializer::serialize(&data);
		std::cout << "Serialized copy uintptr_t: " << serialized_copy << std::endl;
		std::cout << "Serialized original data uintptr_t: " << serialized_data
				<< std::endl;

		std::cout << "\n==== Deserialized copy ====" << std::endl;
		Data* deserialized_copy = Serializer::deserialize(serialized_copy);
		std::cout << "Deserialized copy data: {" << deserialized_copy->index
				<< "}, {" << deserialized_copy->name << "}" << std::endl;
		std::cout << "Deserialized copy address: " << deserialized_copy
				<< std::endl;

		std::cout << "\n==== Check copy pointers ====" << std::endl;
		if (deserialized_copy == &data) {
			std::cout << "Deserialized copy matches original data! UNEXPECTED!"
				<< std::endl;
		} else if (deserialized_copy == copy) {
			std::cout << "Deserialized copy matches copy! Success!" << std::endl;
		} else {
			std::cout << "Deserialized copy does not match either \
				original data or copy! UNEXPECTED!" << std::endl;
		}
		delete copy;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
