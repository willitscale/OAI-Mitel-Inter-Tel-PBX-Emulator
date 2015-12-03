#include "stdafx.h"

namespace OAI_Common
{
	extern const short ENDIAN_LENGTH = 3;
	extern const short BYTE_SIZE = 256;

	extern const byte LINEBREAK = 0x0D;
	extern const byte BREAK = 0x00;

	class ConsoleLock : public Lockable {};

	// Debugging output
	extern void Console(std::string message);

	// Convert a little endian byte array to an integer e.g. 
	extern int FromLittleEndian(char* bytes);

	// Convert an integer to a little endian byte array
	extern char* ToLittleEndian(int size);
}
