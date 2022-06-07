#pragma once
#include <fstream>
#include <string>
#include <array>


class fileIO {
public:
	void appendToFile(const std::string& x, std::string fileName)
	{
		std::fstream file;
		file.open(fileName + ".txt", std::ios::out | std::ios::app); //std::ios::out|std::ios:app to append
		file << x << '\n';
		file.close();
	}
	//Append given type to file
	std::string readFromFile(int fileName)
	{
		std::fstream file;
		std::string str = "";
		file.open(fileName + ".txt", std::ios::in);
		for (std::string line; std::getline(file, line); )
		{
			str.append(line + '\t');
		}
		file.close();
		return str;
	}
};
//Saves array to file where enters means new row







//std::string readFromFileZwei(std::string fileName)
//{
//
//	//std::fstream file;
//	std::string str = "";
//	//file.open(fileName + ".txt", std::ios::in);
//	//for (std::string line; std::getline(file, line); )
//	//{
//	//	str.append(line + '\t');
//	//}
//	//file.close();
//	return str;
//}