/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:11:31 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/02 10:18:03 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <cstdint>

struct Data
{
	int			index;
	std::string	name;
};

class Serializer
{
	public:
		Serializer() = delete;
		~Serializer() = delete;
		Serializer(const Serializer &other) = delete;
		Serializer &operator=(const Serializer &other) = delete;
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
