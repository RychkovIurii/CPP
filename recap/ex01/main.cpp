/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:06:10 by irychkov          #+#    #+#             */
/*   Updated: 2025/08/25 17:01:35 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.hpp"
#include "ATarget.hpp"
#include "AMagic.hpp"
#include <iostream>

class Dummy : public ATarget {
	public:
		Dummy() : ATarget("someType") {}
		~Dummy() {}
		ATarget *clone() const { return new Dummy();}
};

class Fwoosh : public AMagic {
	public:
		Fwoosh() : AMagic("someName", "someEffect") {}
		~Fwoosh() {}
		AMagic *clone() const { return new Fwoosh();}
};

int main( void )
{
	{
		 Unit richard("Richard", "the Titled");

		Dummy bob;
		Fwoosh* fwoosh = new Fwoosh();

		richard.learnSpell(fwoosh);

		richard.introduce();
		richard.launchSpell("someName", bob);

		richard.forgetSpell("someName");
		richard.launchSpell("someName", bob);
	}

  return (0);
}