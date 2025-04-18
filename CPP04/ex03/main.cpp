/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:59 by irychkov          #+#    #+#             */
/*   Updated: 2025/04/18 16:54:40 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include <exception>

int	main( void )
{
	Ice ice;
	ice.use();
	Cure cure;
	cure.use();
	return (0);
}
