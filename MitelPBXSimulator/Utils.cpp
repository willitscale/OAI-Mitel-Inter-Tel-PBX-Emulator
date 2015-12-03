#include "stdafx.h"

namespace OAI_Common
{
	ConsoleLock consoleSync;

	void Console(std::string message)
	{
		// Make sure we don't have more than 1 thing writing to
		// the output buffer at any one time
		synchronized(consoleSync)
		{
			std::cout << message << std::endl;
		}
	}

	int FromLittleEndian(char* bytes)
	{
		return 0;
	}

	char* ToLittleEndian(int size)
	{
		char* ptr = "xyz";

		return ptr;
	}
}
