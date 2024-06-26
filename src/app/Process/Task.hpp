#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "../filehandeling/IO.hpp"

enum class Action
{
	ENCRYPT,
	DECRYPT
};

struct Task
{
	std::string filePath;
	std::fstream f_stream;
	Action action;

	Task(std::fstream &&stream, Action act, std::string filePath) // here we have used && what it mean? && will not store the thing it just create the copy and then pass it like if we do it by pass by refereanct then it will getsstore at that point and then pass to other variabel
																  // we can it is valatile it is an temperary buffer
		: f_stream(std::move(f_stream), action(act), filePath(filePath))
	{
	}

	std::string toString()
	{
		std::ostringstream oss;
		// oss << "File path: " << filePath << std::endl;
		// oss << "Action: " << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT") << std::endl;
		oss << filePath << "," << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
		return oss.str();
	}

	static Task fromString(const std::string &taskData)
	{
		std::istringstream iss(taskData);
		std::string filePath;
		std::string action;

		if (std::getline(iss, filePath, ',') && std::getline(iss, action))
		{

			Action action = (action == "ENCRYPT" ? Action::Encrypt : Action::Decrypt);
			IO io(filePath);
			std::fstream f_stream = std::move(io.getfileStream());
			if (f_stream.is_open())
			{
				return Task(std::move(f_stream), action, filePath);
			}
			else
			{
				throw std::runtime_error("Fail to open file " + filePath);
			}
		}
		else
		{
			throw std::runtime_error("Fail to parse task data format");
		}
	}
};

#endif