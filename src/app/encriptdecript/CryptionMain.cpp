#include <iostream>
#include "../encriptdecript/Cryption.hpp"

int main(int args, char *argv[])
{
	if (args != 2)
	{
		std::cerr << "Usage: ./cryption <task_data>" << std::endl;
		return 1;
	}
	executeEncryption(args[1]);
	return 0;
}