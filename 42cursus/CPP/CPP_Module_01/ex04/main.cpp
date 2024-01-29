/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:05:24 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/07 12:19:03 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static int ft_error(int n)
{
	if (n == 0)
		std::cout << "Argument Num Error." << std::endl;
	else if (n == 1)
		std::cout << "Input File Error." << std::endl;
	else if (n == 2)
		std::cout << "Output File Error." << std::endl;
	return (1);
}

static std::string ft_replace(std::string temp, std::string s1, std::string s2)
{
	size_t 		i;
	size_t 		pos;
	std::string	line;

	pos = temp.find(s1);
	while (pos != std::string::npos)
	{
		i = 0;
		line.append(temp.substr(i, pos));
		line.append(s2);
		i = pos + s1.length();
		temp = temp.substr(i, temp.length());
		pos = temp.find(s1);
	}
	line.append(temp);
	return (line);
}

int main(int ac, char* av[])
{
	std::ifstream 	ifs;
	std::ofstream	ofs;
	std::string 	temp;

	if (ac != 4)
		return(ft_error(0));
	ifs.open(av[1]);
	if (ifs.fail())
		return(ft_error(1));
	temp = std::string(av[1]) + ".replace";
	ofs.open(temp.c_str());
	if (ofs.fail())
		return(ft_error(2));
	while (std::getline(ifs, temp))
	{
		if(temp.find(std::string(av[2])) != std::string::npos)
			temp = ft_replace(temp, std::string(av[2]), std::string(av[3]));
		ofs << temp << std::endl;
	}

	ifs.close();
	ofs.close();
	return (0);
}