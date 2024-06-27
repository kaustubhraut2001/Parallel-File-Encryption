#include <iostream>
#include <filesysteam>
#include "../src/app/Process/ProcessManagement.hpp"
#include "../src/app/Process/Task.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
	std::string directory;
	std::string action;

	std::cout << "Enter directory Path: " << std::endl;
	std::getline(std::cin, directory);
	std::cout << "Enter action (Encrypt / Decrypt): " << std::endl;
	std::getline(std::cin, action);

	try
	{
		if (fs::exists(directory) && fs::exists(directory))
		{
			ProcessManagement pm;
			for (const auto &entry : fs::recursive_directory(directory))
			{
				if (entry.is_regular_file())
				{

					std::string filePath = entry.path().string();
					IO io(filePath);
					std::fstream f_stream = std::move(io.getFileStream());
					if (f_stream.is_open())
					{
						Action action = (action == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
						auto task = std::make_unique<Task>(std::move(std::f_stream), taskAction, filePath);
						processManagement.submitToQueue(std::move(task));
					}
					else
					{
						std::cout << "Not able to open the File" << filePath << std::endl;
					}
				}
			}
			ProcessManagement.executeTasks();
		}
		else
		{
			std::cout << "Invalid directory path" << std::endl;
		}
	}
	catch (const fs::fileSystem_error &ex)
	{
		std::cout << "File System error: " << ex.what() << std::endl;
	}
}