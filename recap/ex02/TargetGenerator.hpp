/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:32 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 20:09:04 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <map>

class ATarget;

class TargetGenerator {
	private:
		std::map<std::string, ATarget *> _types;
		TargetGenerator(TargetGenerator &obj) = delete;
		TargetGenerator &operator=(TargetGenerator &obj) = delete;
	public:
		TargetGenerator( void );
		~TargetGenerator( void );
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};