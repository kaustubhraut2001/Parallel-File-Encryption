#include "../ProcessManagement.hpp"
#include <iostream>
#include <string>
#include <sys/wait.h>
// #include "../"

ProcessManagement::ProcessManagement() {}

bool ProcessManagement::sumitToQueue(std::unique_ptr<Task> task)
{
	taskqueue.push(std::move(task));
	return true;
}

void ProcessManagement::execute()
{
	while (!taskqueue.empty())
	{
		std::unique_ptr<Task> tasktoExecute = std::move(taskqueue.front());
		taskqueue.pop();
		std::cout << "Executin task " << tasktoExecute->toString() << std::endl;
	}
}