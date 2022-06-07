#pragma once
#include <fstream>
#include <string>
#include <array>


class FileIO {
public:
	//Appends string to file where enters means new row 
	static void appendToFile(const std::string& x, std::string fileName)
	{
		std::fstream file;
		file.open(fileName + ".txt", std::ios::out | std::ios::app); //std::ios::out|std::ios:app to append
		file << x << '\n';
		file.close();
	}
	
	//Reads scores from file where enters mean new row
	static std::string readFromFile(std::string fileName)
	{
		std::fstream file;
		std::string str = "";
		file.open(fileName + ".txt", std::ios::in);
		for (std::string line; std::getline(file, line); )
		{
			str.append(line + '\n');
		}
		file.close();
		return str;
	}
};
