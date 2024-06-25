#ifndef IO_HPP // this mean if not define then we are defining it in the below line
#define IO_HPP

// including the header files
#include <fstream>
#include <string>

class IO
{
public:
	IO(const std::string &filepath); // we are making the condtrsucter it will take the file path here which will not change so we are making it const
	~IO();							 // as every constructor has an destructor method we are defingin it

	std::fstream getfileStream();

private:
	std::fstream fileStream;
};

#endif // ending of this code block

// this file only consistes of the defination we are giving the implementation in IO.cpp file