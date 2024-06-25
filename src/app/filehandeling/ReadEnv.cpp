#include <iostream>
#include <string>
#include <fstream>
#include "IO.hpp"
#include <string>
#include <sstream>

class ReadEnv
{

public:
	std::readEnv()
	{
		// function to read env file from the root
		std::string env_filepath = ".env";
		IO io(env_filepath);
		std::fstream f_stream = io.getFileStream();
		std::stringstream buffer;
		buffer << f_stream.rdbuf();
		std::string content = buffer.str();
		return content;
	}
};
