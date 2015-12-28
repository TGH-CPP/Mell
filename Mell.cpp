// Mell.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void commands(std::vector<std::string>& i)
{
	if (i.empty())
	{
		std::cout << "No input found. Try again." << std::endl;
		return;
	}
	else
	{
		std::cout << "Input found was: ";
		for (std::vector<std::string>::const_iterator x = i.begin(); x != i.end(); x++)
			std::cout << *x << ' ';
		std::cout << std::endl << "With length of: " << i.size() << std::endl;
	}
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

int main(int argc, _TCHAR* argv[])
{
	std::string input;
	while (std::getline(std::cin, input)){
		std::vector<std::string> commin = split(input, ' ');
		commands(commin);
	}
	return 0;
}