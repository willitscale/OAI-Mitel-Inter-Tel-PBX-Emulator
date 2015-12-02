#include "stdafx.h"

namespace OAI_Networking
{
	Client::Client(int client) : m_Socket(client)
	{

	}

	Client::~Client()
	{
		x__close(m_Socket);
	}

	void Client::run()
	{
		for (;;) {
			// Read all the data before we start writing
			this->read();
			this->write("test");
		}
	}

	int Client::read()
	{
		int bytes = 0;

		bzero(m_Buffer, BUFFER_SIZE);

		bytes = x__read(m_Socket, m_Buffer, BUFFER_SIZE - 1);

		// We read to the maximum size of the buffer so presume
		// there could be more to read
		if (BUFFER_SIZE == bytes)
		{
			return bytes + this->read();
		}

		return bytes;
	}

	int Client::write(std::string message)
	{
		int bytes = 0, offset = 0, length = 0, maxLength = message.length();

		// We only have a limited block size so iteration time
		while (offset < maxLength) {

			strncpy_s(m_Buffer, message.c_str() + offset, BUFFER_SIZE);

			length = BUFFER_SIZE;

			// The maximum amount of bytes we're sending e.g. if 
			// the buffer size is 1024 and the message length is
			// 1030 then amount of bytes sent should be:
			// * Chunk 1 - 1024
			// * Chunk 2 - 6
			if (offset + BUFFER_SIZE > maxLength) {
				length = maxLength - offset;
			}

			bytes += x__write(m_Socket, m_Buffer, length);

			offset += BUFFER_SIZE;
		}

		return bytes;
	}
}