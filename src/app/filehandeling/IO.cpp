// this file is the implemetaion if the IO.hpp file
#include <iostream>
#include "IO.hpp"
#include <fstream>

// implemetaion of the constructor that we have declier in the IO.hpp file

IO::IO(const std::string &file_path)
{
	fileStream.open(file_path, std::ios::in | std::ios::out | std::ios::binary); // these are input output functional calls we are doing here
	if (!fileStream.is_open())													 // if we are facing any issue in opening the file
	{
		std::cout << "Error opening file" << file_path << std::endl;
	}
}

fstream IO::getfileStream()
{
	return std::move(fileStream); // we are returing the filestream here
}

IO::~IO()
{
	if (fileStream.is_open())
	{
		fileStream.close(); // the destructor closing the file stream if it is open
	}
}