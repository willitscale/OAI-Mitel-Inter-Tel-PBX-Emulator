#include "stdafx.h"

namespace OAI_Common
{
	const short ENDIAN_LENGTH = 3;
	const short BYTE_SIZE = 256;

	const byte LINEBREAK = 0x0D;
	const byte BREAK = 0x00;

	class ConsoleLock : public Lockable {};

	ConsoleLock consoleSync;

	// Debugging output
	//void Console(std::string message);
	void Console(std::string message)
	{
		// Make sure we don't have more than 1 thing writing to
		// the output buffer at any one time
		synchronized(consoleSync)
		{
			std::cout << message << std::endl;
		}
	}

	// Convert a little endian byte array to an integer e.g. 
	int FromLittleEndian(char* bytes);

	// Convert an integer to a little endian byte array
	char* ToLittleEndian(int size);
}
