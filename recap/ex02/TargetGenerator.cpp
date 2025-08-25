/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:30:35 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 20:29:24 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator :: TargetGenerator() {}

TargetGenerator :: ~TargetGenerator() {
	_types.clear();
}

void TargetGenerator :: learnTargetType(ATarget* target) {
	if (target != nullptr) {
		std::map<std::string, ATarget *>::iterator it = _types.find(target->getType());
		if (it == _types.end())
			_types[target->getType()] = target;
	}
}

void TargetGenerator :: forgetTargetType(std::string const &targetName) {
	std::map<std::string, ATarget *>::iterator it = _types.find(targetName);
	if (it != _types.end()) {
		_types.erase(targetName);
	}
}

ATarget* TargetGenerator :: createTarget(std::string const &targetName) {
	std::map<std::string, ATarget *>::iterator it = _types.find(targetName);
	if (it != _types.end()) {
		return it->second->clone();
	}
	return nullptr;
}