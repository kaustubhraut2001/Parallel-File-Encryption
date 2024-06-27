#include "../encriptdecript/Cryption.hpp"
#include "../Process/Task.hpp"
#include "../filehandeling/ReadEnv.cpp"

int executeEncryption(const std::string &taskData)
{
	Task task = Task::fromString(taskData);
	ReadEnv env;

	std::string envKey = env.getKey();
	int key = std::stoi(envkey);

	if (task.action == Action::ENCRYPT)
	{
		char ch;
		while (task.f_stream.get(ch))
		{
			ch = (ch + key) % 256;
			task.f_stream.seekp(-1, std::ios::cur);
			task.f_stream.put(ch);
		}
		task.f_stream.close();
	}
	else
	{
		char ch;
		while (task.f_stream.get(ch))
		{
			ch = (ch - 256) % 256;
			task.f_stream.seekp(-1, std::ios::cur);
			task.f_stream.put(ch);
		}
		task.f_stream.close();
	}
	return 0;
}