/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:19:17 by irychkov          #+#    #+#             */
/*   Updated: 2025/03/25 15:10:41 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <filesystem>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		return (0);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file(filename);
	if (s1.empty() || filename.empty())
	{
		std::cerr << "Error: s1 and filename must not be empty" << std::endl;
		return (1);
	}
	std::cout << "s1: {" << s1 << "}" << std::endl;
	std::cout << "s2: {" << s2 << "}" << std::endl;
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
	new_file << line;
	return (0);
}
