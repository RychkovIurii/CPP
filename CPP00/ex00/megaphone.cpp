/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:50:41 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/13 14:07:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using std::cout;

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			cout << static_cast<char>(
				std::toupper(static_cast<unsigned char>(argv[i][j])));
		}
	}
	cout << std::endl;
	return (0);
}
