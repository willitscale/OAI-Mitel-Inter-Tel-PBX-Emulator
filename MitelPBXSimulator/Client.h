#include "stdafx.h"

namespace OAI_Networking
{
	class Client : public Lockable
	{
	public:
		Client(int client);
		~Client();

		const static int BUFFER_SIZE = 1024;

	protected:
		int m_Socket;
		char m_Buffer[BUFFER_SIZE];

		void run();
		int read();
		int write(std::string message);
	};
}