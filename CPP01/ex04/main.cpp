/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:19:17 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/25 15:51:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <filesystem>

static void	check_args(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		exit (0);
	}
	if (argv[2][0] == '\0' || argv[1][0] == '\0')
	{
		std::cerr << "Error: s1 and filename must not be empty" << std::endl;
		exit (1);
	}
}

static void	replace(std::string &line, std::string s1, std::string s2)
{
	std::string new_line;
	std::size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		new_line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		line = new_line;
		pos += s2.length();
	}
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file(filename);
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file" << filename << std::endl;
		return (1);
	}
	std::filesystem::path oldpath = filename;
	std::string new_filename = oldpath.stem().string() + ".replace" + oldpath.extension().string();
	std::ofstream new_file(new_filename);
	if (!new_file.is_open())
	{
		std::cerr << "Error: could not create new file" << new_filename << std::endl;
		return (1);
	}
	std::string line;
	std::getline(file, line, '\0');
	if (s1 != s2)
		replace(line, s1, s2);
	new_file << line;
	return (0);
}
