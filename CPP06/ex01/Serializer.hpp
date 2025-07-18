/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:11:31 by irychkov          #+#    #+#             */
/*   Updated: 2025/07/02 14:26:10 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"
#include <cstdint>

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
