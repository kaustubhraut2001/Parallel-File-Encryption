#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "../Task.hpp"
#include <memory>
#include <queue>

class ProcessManagement
{
public:
	ProcessManagement();
	bool sumitToQueue(std::unique_ptr<Task> task);
	void executeTasks();

private:
	std::queue<std::unique_ptr<Task>> taskqueue;
};

#endif